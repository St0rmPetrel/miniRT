/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:32:20 by serma             #+#    #+#             */
/*   Updated: 2021/02/03 15:07:28 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "ray.h"
#include "vectormath.h"
#include "ray_trace.h"
#include <math.h>

t_color	ambient_lighting(t_intersection hit, t_light light)
{
	t_color		ret_color;

	ret_color = give_color(hit.material.color, light.color, light.intensity);
	return (ret_color);
}

t_ray	give_shadow_ray(t_intersection hit, t_light light)
{
	t_ray		ret_ray;
	t_point		light_center;
	t_vector	light_direction;

	ret_ray.origin = calculate(hit.ray, hit.t);
	ret_ray.t_max = RAY_T_MAX;
	if (light.type == POINT_LIGHT)
	{
		light_center = ((t_point_light *)(light.data))->center;
		ret_ray.direction = vec_sub((t_vector)light_center, \
			(t_vector)(ret_ray.origin));
		ret_ray.t_max = vec_length(ret_ray.direction);
	}
	else if (light.type == DIRECT_LIGHT)
	{
		light_direction = ((t_direct_light *)(light.data))->direction;
		ret_ray.direction = vec_normalize(vec_mul(light_direction, -1));
	}
	else
		ret_ray.direction = vec_set(0, 0, 0);
	ret_ray.direction = vec_normalize(ret_ray.direction);
	ret_ray.refl_deep = 0;
	ret_ray.refr_deep = 0;
	return (ret_ray);
}

double	give_pow_cos(t_ray shadow_ray, t_intersection hit)
{
	t_ray		reverse_shadow_ray;
	t_vector	light_dir;
	t_vector	view_dir;
	double		ret;
	t_vector	middle_ray_dir;

	if (hit.material.specular == 0)
		return (0);
	view_dir = vec_mul(hit.ray.direction, -1);
	reverse_shadow_ray = shadow_ray;
	reverse_shadow_ray.direction = vec_mul(shadow_ray.direction, -1);
	light_dir = (ray_reflect(reverse_shadow_ray, hit)).direction;
	middle_ray_dir = vec_normalize(vec_add(light_dir, view_dir));
	ret = vec_dot(middle_ray_dir, hit.normal);
	if (ret < 0)
		return (0);
	ret = pow(ret, hit.material.specular);
	return (ret);
}

t_color	point_lighting(t_intersection hit, t_light light, t_list *objects)
{
	t_color ret_color;
	t_color diffuse_color;
	t_ray	shadow_ray;
	double	normal_shadow_dot;
	double	pow_cos;

	shadow_ray = give_shadow_ray(hit, light);
	ret_color = BACK_GROUND_COLOR;
	if (ray_does_scene_intersection(shadow_ray, objects))
		return (ret_color);
	ret_color = hit.material.color;
	normal_shadow_dot = vec_dot(hit.normal, shadow_ray.direction);
	if (normal_shadow_dot < 0)
		return (BACK_GROUND_COLOR);
	diffuse_color = give_color(hit.material.color, light.color,
			light.intensity * normal_shadow_dot);
	if (hit.material.specular == NO_SPECULAR)
		return (diffuse_color);
	pow_cos = give_pow_cos(shadow_ray, hit);
	ret_color = give_color(hit.material.color, light.color,
			light.intensity * pow_cos);
	ret_color = color_add(ret_color, diffuse_color);
	return (ret_color);
}

t_color	direct_lighting(t_intersection hit, t_light light, t_list *objects)
{
	t_color ret_color;
	t_color diffuse_color;
	t_ray	shadow_ray;
	double	pow_cos;
	double	normal_shadow_dot;

	shadow_ray = give_shadow_ray(hit, light);
	ret_color = BACK_GROUND_COLOR;
	if (ray_does_scene_intersection(shadow_ray, objects))
		return (ret_color);
	ret_color = hit.material.color;
	normal_shadow_dot = vec_dot(hit.normal, shadow_ray.direction);
	if (normal_shadow_dot < 0)
		return (BACK_GROUND_COLOR);
	diffuse_color = give_color(hit.material.color, light.color,
			light.intensity * normal_shadow_dot);
	if (hit.material.specular == NO_SPECULAR)
		return (diffuse_color);
	pow_cos = give_pow_cos(shadow_ray, hit);
	ret_color = give_color(hit.material.color, light.color,
			light.intensity * pow_cos);
	ret_color = color_add(ret_color, diffuse_color);
	return (ret_color);
}
