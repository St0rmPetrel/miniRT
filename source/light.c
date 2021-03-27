/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:30:45 by serma             #+#    #+#             */
/*   Updated: 2021/01/27 17:11:54 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "scene.h"
#include "colors.h"
#include "lighting.h"

t_color		lighting_color(t_intersection hit, t_scene scene)
{
	t_light	current_light;
	t_color	ret_color;

	ret_color = BACK_GROUND_COLOR;
	while (scene.lights)
	{
		current_light = *(t_light *)((scene.lights)->content);
		if (current_light.type == AMBIENT_LIGHT)
		{
			ret_color = color_add(ret_color, \
					ambient_lighting(hit, current_light));
		}
		else if (current_light.type == POINT_LIGHT)
		{
			ret_color = color_add(ret_color, \
					point_lighting(hit, current_light, scene.objects));
		}
		else if (current_light.type == DIRECT_LIGHT)
		{
			ret_color = color_add(ret_color, \
					direct_lighting(hit, current_light, scene.objects));
		}
		scene.lights = (scene.lights)->next;
	}
	return (ret_color);
}
