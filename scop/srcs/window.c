/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:12:09 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/02 18:07:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double g_previous_seconds = 0;

GLFWwindow	*open_window(char *name)
{
	GLFWwindow	*window;
	
	window = glfwCreateWindow(GL_WIDTH, GL_HEIGHT, name, NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(window);
	return (window);
}

void		update_fps_counter(GLFWwindow *window) {
	static int	frame_count;
	double		current_seconds;
	double		elapsed_seconds;
	double		fps;
	char		tmp[128];

	current_seconds = glfwGetTime();
	elapsed_seconds = current_seconds - g_previous_seconds;
	if (elapsed_seconds > 0.25)
	{
		g_previous_seconds = current_seconds;
		fps = (double)frame_count / elapsed_seconds;
		sprintf(tmp, "opengl @ fps: %.2f", fps);
		glfwSetWindowTitle(window, tmp);
		frame_count = 0;
	}
	frame_count++;
}

void		draw(GLFWwindow *window, GLuint shader_program, GLuint vao, t_obj obj)
{
	float	lastFrame;
	float	currentFrame;

	lastFrame = 0.0f;
	glClearColor(0.6, 0.6, 0.8, 1.0);
	g_previous_seconds = glfwGetTime();
	g_sh_vars.timer = 0.0f;
	g_sh_vars.trans.x = 0.0f;
	g_sh_vars.trans.y = 0.0f;
	g_sh_vars.trans.z = 0.0f;
	while (!glfwWindowShouldClose(window))
	{
		currentFrame = glfwGetTime();
		g_delta_time = currentFrame - lastFrame;
		lastFrame = currentFrame;
		update_fps_counter(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_program);
		glUniform1f(glGetUniformLocation(shader_program, "timer"), g_sh_vars.timer);
		g_sh_vars.timer += 0.01f;
		glUniform3f(glGetUniformLocation(shader_program, "trans"), g_sh_vars.trans.x, g_sh_vars.trans.y, g_sh_vars.trans.z);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, obj.texture);
		glUniform1f(glGetUniformLocation(shader_program, "textureAlpha"), g_tex_alpha);
		g_tex_alpha += g_modif_tex_alpha;
		if (g_tex_alpha >= 1.0 || g_tex_alpha <= 0.0)
			g_modif_tex_alpha = 0.0;
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, obj.nb_points);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}