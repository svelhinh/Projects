/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 17:51:30 by svelhinh          #+#    #+#             */
/*   Updated: 2018/07/02 17:51:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	print_shader_info_log(GLuint shader_index)
{
	int		max_length;
	int		actual_length;
	char	shader_log[2048];

	max_length = 2048;
	actual_length = 0;
	glGetShaderInfoLog(shader_index, max_length, &actual_length, shader_log);
	printf("shader info log for GL index %u:\n%s\n", shader_index, shader_log);
}

void	print_programme_info_log(GLuint programme)
{
	int		max_length;
	int		actual_length;
	char	program_log[2048];

	max_length = 2048;
	actual_length = 0;
	glGetProgramInfoLog(programme, max_length, &actual_length, program_log);
	printf("program info log for GL index %u:\n%s", programme, program_log);
}

void	print_all(GLuint programme)
{
	int		params;
	char	name[64];
	int		max_length;
	int		actual_length;
	int		size;
	GLenum	type;
	char	long_name[64];
	int		location;
	
	printf("--------------------\nshader programme %i info:\n", programme);
	params = -1;
	glGetProgramiv(programme, GL_LINK_STATUS, &params);
	printf("GL_LINK_STATUS = %i\n", params);

	glGetProgramiv(programme, GL_ATTACHED_SHADERS, &params);
	printf("GL_ATTACHED_SHADERS = %i\n", params);

	glGetProgramiv(programme, GL_ACTIVE_ATTRIBUTES, &params);
	printf("GL_ACTIVE_ATTRIBUTES = %i\n", params);
	for (int i = 0; i < params; i++)
	{
		max_length = 64;
		actual_length = 0;
		size = 0;
		glGetActiveAttrib (
			programme,
			i,
			max_length,
			&actual_length,
			&size,
			&type,
			name
		);
		if (size > 1)
		{
			for (int j = 0; j < size; j++)
			{
				sprintf(long_name, "%s[%i]", name, j);
				location = glGetAttribLocation(programme, long_name);
				printf("  %i) type:%s name:%s location:%i\n",
					i, gl_type_to_string(type), long_name, location);
			}
		}
		else
		{
			int location = glGetAttribLocation(programme, name);
			printf("  %i) type:%s name:%s location:%i\n",
				i, gl_type_to_string(type), name, location);
		}
	}

	glGetProgramiv(programme, GL_ACTIVE_UNIFORMS, &params);
	printf("GL_ACTIVE_UNIFORMS = %i\n", params);
	for (int i = 0; i < params; i++)
	{
		max_length = 64;
		actual_length = 0;
		size = 0;
		GLenum type;
		glGetActiveUniform(
			programme,
			i,
			max_length,
			&actual_length,
			&size,
			&type,
			name
		);
		if (size > 1)
		{
			for (int j = 0; j < size; j++)
			{
				sprintf(long_name, "%s[%i]", name, j);
				location = glGetUniformLocation(programme, long_name);
				printf("  %i) type:%s name:%s location:%i\n",
					i, gl_type_to_string(type), long_name, location);
			}
		}
		else
		{
			location = glGetUniformLocation(programme, name);
			printf("  %i) type:%s name:%s location:%i\n",
				i, gl_type_to_string(type), name, location);
		}
	}
	print_programme_info_log(programme);
}
