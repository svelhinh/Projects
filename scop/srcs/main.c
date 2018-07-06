/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:03:15 by svelhinh          #+#    #+#             */
/*   Updated: 2018/06/29 18:49:57 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int	main(int ac, char **av)
{
	t_obj		obj;
	float		*colors;
	GLFWwindow	*window;
	GLuint		vao;
	const char	*vertex_shader;
	const char	*fragment_shader;
	GLuint		shader_program;
	int			i;
	float		color;

	if (ac != 2)
		ft_puterror("Wrong number of arguments");
	parsing_obj(&obj, av[1]);
	recenter_object(&obj);
	window = NULL;
	init_all(&window);
	obj.texture = load_texture();
	srand(time(NULL));
	if (!(colors = (float *)malloc(sizeof(float) * obj.nb_points * 3)))
		ft_puterror("malloc failed");
	i = 0;
	while (i < obj.nb_points * 3)
	{
		color = (float)rand_between_2_numbers(50, 205) / 255.0f;
		colors[i] = color;
		colors[i + 1] = color;
		colors[i + 2] = color;
		colors[i + 3] = color;
		colors[i + 4] = color;
		colors[i + 5] = color;
		colors[i + 6] = color;
		colors[i + 7] = color;
		colors[i + 8] = color;
		i += 9;
	}
	vao = copy_to_gpu(obj.points, colors, obj.nb_points);
	vertex_shader = read_vertex_shader();
	fragment_shader = read_fragment_shader();
	shader_program = create_shaders(vertex_shader, fragment_shader);
	set_key_events(window);
	draw(window, shader_program, vao, obj);
	glfwTerminate();
	return (0);
}
