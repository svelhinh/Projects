/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:45:44 by svelhinh          #+#    #+#             */
/*   Updated: 2018/06/29 19:54:17 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include <stdarg.h>
# include <assert.h>
# include <math.h>
# include "libft.h"
# include "glew.h"
# include "glfw3.h"

# define GL_LOG_FILE "gl.log"
# define GL_WIDTH 1280
# define GL_HEIGHT 720
# define S_IFMT 0170000
# define S_IFDIR 0040000
# define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_obj
{
	float		*points;
	int			nb_points;
	float		*colors;
	t_vec3		center_pt;
	GLuint		texture;
}				t_obj;

typedef struct	s_sh_vars
{
	GLint		timer_loc;
	GLfloat		timer;
	t_vec3		trans;
}				t_sh_vars;

extern double	g_previous_seconds;
t_sh_vars		g_sh_vars;
float			g_delta_time;
float			g_tex_alpha;
float			g_modif_tex_alpha;

void			init_all(GLFWwindow **window);
GLuint			load_texture();

GLFWwindow		*open_window(char *name);
void			draw(GLFWwindow *window, GLuint shader_program, GLuint vao,
	t_obj obj);

void			set_key_events(GLFWwindow *window);

GLuint			copy_to_gpu(float *points, float *colors, float nb_points);
const char		*read_vertex_shader();
const char		*read_fragment_shader();
GLuint			create_shaders(const char *vertex_shader,
	const char *fragment_shader);
int				shader_is_valid(GLuint programme);

void			glfw_error_callback(int error, const char *description);
int				gl_log_err(const char *message, ...);
int				gl_log(const char *message, ...);
int				restart_gl_log();
void			log_gl_params();
void			print_shader_info_log(GLuint shader_index);
void			print_programme_info_log(GLuint programme);

void			check_shader_compilation_errors(GLuint shader_index);
void			check_shader_linking_errors(GLuint programme);

const char		*gl_type_to_string(GLenum type);
int				rand_between_2_numbers(int min, int max);
void			recenter_object(t_obj *obj);
int				is_dir(const char *path);

void			parsing_obj(t_obj *obj, char *obj_file);

#endif
