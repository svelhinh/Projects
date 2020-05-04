/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:41:19 by svelhinh          #+#    #+#             */
/*   Updated: 2018/06/29 19:54:30 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	check_shader_compilation_errors(GLuint shader_index)
{
	int params;

	params = -1;
	glGetShaderiv(shader_index, GL_COMPILE_STATUS, &params);
	if (GL_TRUE != params)
	{
		fprintf(stderr, "ERROR: GL shader index %i did not compile\n",
		shader_index);
		print_shader_info_log(shader_index);
		exit(1);
	}
}

void	check_shader_linking_errors(GLuint programme)
{
	int params;

	params = -1;
	glGetProgramiv(programme, GL_LINK_STATUS, &params);
	if (GL_TRUE != params)
	{
		fprintf(stderr,
		"ERROR: could not link shader programme GL index %u\n",
			programme);
		print_programme_info_log(programme);
		exit(1);
	}
}
