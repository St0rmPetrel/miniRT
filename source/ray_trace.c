/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:09:13 by serma             #+#    #+#             */
/*   Updated: 2021/01/27 17:06:48 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "lighting.h"

t_color	ray_trace(t_ray ray, t_scene *scene)
{
	t_color			ret_color;
	t_intersection	hit;
	double			alpha;

	ret_color = BACK_GROUND_COLOR;
	hit = ray_scene_intersection(ray, scene->objects);
	if (!hit.exist)
		return (ret_color);
	ret_color = lighting_color(hit, *scene);
	alpha = hit.material.color.alpha;
	if (alpha > 0)
		ret_color = color_mul(ret_color, ((1 - alpha) / 2.));
	if ((hit.material.reflection > 0) && (ray.refl_deep <= MAX_REFL_DEEP))
	{
		ret_color = color_add(color_mul(ray_trace(ray_reflect(ray, hit), \
						scene), hit.material.reflection), ret_color);
	}
	if ((alpha > 0) && (ray.refr_deep <= MAX_REFR_DEEP))
	{
		ret_color = color_add(ret_color, \
				color_mul(ray_trace(ray_refract(ray, hit), scene), alpha));
	}
	return (ret_color);
}
