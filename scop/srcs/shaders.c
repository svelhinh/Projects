/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:27:09 by svelhinh          #+#    #+#             */
/*   Updated: 2018/06/29 19:54:35 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

GLuint		copy_to_gpu(float *points, float *colors, float nb_points)
{
	GLuint	points_vbo;
	GLfloat	*uvs;
	int		i;
	GLuint	uv_vbo;
	GLuint	colors_vbo;
	GLuint	vao;

	nb_points *= 3;
	glGenBuffers(1, &points_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glBufferData(GL_ARRAY_BUFFER, nb_points * sizeof(float), points,
		GL_STATIC_DRAW);
	if (!(uvs = (GLfloat *)malloc(sizeof(GLfloat) * nb_points * 2)))
		ft_puterror("malloc failed");
	i = 0;
	while (i < nb_points)
	{
		uvs[i] = 0.0;
		uvs[i + 1] = 1.0;
		uvs[i + 2] = 0.0;
		uvs[i + 3] = 0.0;
		uvs[i + 4] = 1.0;
		uvs[i + 5] = 1.0;
		i += 6;
	}
	glGenBuffers(1, &uv_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, uv_vbo);
	glBufferData(GL_ARRAY_BUFFER, nb_points * 2 * sizeof(float), uvs,
		GL_STATIC_DRAW);
	glGenBuffers(1, &colors_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
	glBufferData(GL_ARRAY_BUFFER, nb_points * sizeof(float), colors,
		GL_STATIC_DRAW);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, uv_vbo);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colors_vbo);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(2);
	return (vao);
}

const char	*read_vertex_shader(void)
{
	FILE *file;
	char *line;
	char *shader;

	shader = "";
	if ((file = fopen("shaders/test_vs.glsl", "r")) == NULL)
		ft_puterror("open file failed");
	while (get_next_line(fileno(file), &line))
		shader = ft_strjoin(ft_strjoin(shader, line), "\n");
	fclose(file);
	return (shader);
}

const char	*read_fragment_shader(void)
{
	FILE *file;
	char *line;
	char *shader;

	shader = "";
	if ((file = fopen("shaders/test_fs.glsl", "r")) == NULL)
		ft_puterror("open file failed");
	while (get_next_line(fileno(file), &line))
		shader = ft_strjoin(ft_strjoin(shader, line), "\n");
	fclose(file);
	return (shader);
}

GLuint		create_shaders(const char *vertex_shader,
	const char *fragment_shader)
{
	GLuint	vs;
	GLuint	fs;
	GLuint	shader_program;

	vs = glCreateShader(GL_VERTEX_SHADER);
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(vs);
	check_shader_compilation_errors(vs);
	glCompileShader(fs);
	check_shader_compilation_errors(fs);
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vs);
	glAttachShader(shader_program, fs);
	glLinkProgram(shader_program);
	check_shader_linking_errors(shader_program);
	return (shader_program);
}

int			shader_is_valid(GLuint programme)
{
	int params;

	glValidateProgram(programme);
	params = -1;
	glGetProgramiv(programme, GL_VALIDATE_STATUS, &params);
	printf("program %i GL_VALIDATE_STATUS = %i\n", programme, params);
	if (GL_TRUE != params)
	{
		print_programme_info_log(programme);
		return (0);
	}
	return (1);
}
