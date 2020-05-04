/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:00:23 by svelhinh          #+#    #+#             */
/*   Updated: 2018/06/29 18:33:44 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	key_callback(GLFWwindow *window, int key, int scancode,
	int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	else if (key == GLFW_KEY_D && action != GLFW_RELEASE)
		g_sh_vars.trans.x -= 2.5f * g_delta_time;
	else if (key == GLFW_KEY_A && action != GLFW_RELEASE)
		g_sh_vars.trans.x += 2.5f * g_delta_time;
	else if (key == GLFW_KEY_W && action != GLFW_RELEASE)
		g_sh_vars.trans.z -= 2.5f * g_delta_time;
	else if (key == GLFW_KEY_S && action != GLFW_RELEASE)
		g_sh_vars.trans.z += 2.5f * g_delta_time;
	else if (key == GLFW_KEY_PAGE_UP && action != GLFW_RELEASE)
		g_sh_vars.trans.y -= 2.5f * g_delta_time;
	else if (key == GLFW_KEY_PAGE_DOWN && action != GLFW_RELEASE)
		g_sh_vars.trans.y += 2.5f * g_delta_time;
	else if (key == GLFW_KEY_SPACE && action != GLFW_PRESS)
	{
		if (g_tex_alpha >= 1.0)
			g_modif_tex_alpha = -0.01;
		if (g_tex_alpha <= 0.0)
			g_modif_tex_alpha = 0.01;
	}
}

void		set_key_events(GLFWwindow *window)
{
	glfwSetKeyCallback(window, key_callback);
}
