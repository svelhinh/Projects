/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:45:47 by svelhinh          #+#    #+#             */
/*   Updated: 2018/06/29 19:05:12 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	init_glfw(void)
{
	gl_log("starting GLFW\n%s\n", glfwGetVersionString());
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
}

static void	init_glew(void)
{
	const GLubyte	*renderer;
	const GLubyte	*version;

	renderer = glGetString(GL_RENDERER);
	version = glGetString(GL_VERSION);
	glewExperimental = GL_TRUE;
	glewInit();
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	log_gl_params();
}

GLuint		load_texture(void)
{
	unsigned char	header[54];
	unsigned int	data_pos;
	unsigned int	width;
	unsigned int	height;
	unsigned int	image_size;
	unsigned char	*data;
	FILE			*file;
	GLuint			texture_id;

	file = fopen("ressources/poney.bmp", "rb");
	if (!file)
		ft_puterror("Image could not be opened");
	if (fread(header, 1, 54, file) != 54)
		ft_puterror("Not a correct BMP file");
	if (header[0] != 'B' || header[1] != 'M')
		ft_puterror("Not a correct BMP file");
	data_pos = *(int*)&(header[0x0A]);
	image_size = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);
	if (image_size == 0)
		image_size = width * height * 3;
	if (data_pos == 0)
		data_pos = 54;
	if (!(data = (unsigned char *)malloc(sizeof(unsigned char) * image_size)))
		ft_puterror("malloc failed");
	fread(data, 1, image_size, file);
	fclose(file);
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return (texture_id);
}

void		init_all(GLFWwindow **window)
{
	g_modif_tex_alpha = 0.0;
	g_tex_alpha = 0.0;
	assert(restart_gl_log());
	init_glfw();
	*window = open_window("SCOP");
	init_glew();
}
