/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_object_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:52:09 by serma             #+#    #+#             */
/*   Updated: 2021/02/03 15:11:24 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "ray.h"
#include "objects.h"

static double		ray_shape_intersection(t_ray ray, t_object object)
{
	double	ret_t;

	ret_t = 0;
	if (object.type == IS_SPHERE)
		ret_t = ray_sphere_intersection(ray, *((t_sphere *)object.data));
	else if (object.type == IS_PLANE)
		ret_t = ray_plane_intersection(ray, *((t_plane *)object.data));
	else if (object.type == IS_TRIANGLE)
		ret_t = ray_triangle_intersection(ray, *((t_triangle *)object.data));
	else if (object.type == IS_SQUARE)
		ret_t = ray_square_intersection(ray, *((t_square *)object.data));
	else if (object.type == IS_CYLINDER)
		ret_t = ray_cylinder_intersection(ray, *((t_cylinder *)object.data));
	return (ret_t);
}

static t_vector		point_shape_normal(t_point intersec_point, t_object object)
{
	t_vector	ret_normal;

	if (object.type == IS_SPHERE)
	{
		ret_normal = point_sphere_normal(intersec_point, \
				*((t_sphere *)object.data));
	}
	else if (object.type == IS_PLANE)
		ret_normal = point_plane_normal(*((t_plane *)object.data));
	else if (object.type == IS_TRIANGLE)
		ret_normal = point_triangle_normal(*((t_triangle *)object.data));
	else if (object.type == IS_SQUARE)
		ret_normal = point_square_normal(*((t_square *)object.data));
	else if (object.type == IS_CYLINDER)
		ret_normal = point_cylinder_normal(intersec_point,
				*((t_cylinder *)object.data));
	else
		ret_normal = vec_set(0, 0, 0);
	return (ret_normal);
}

t_intersection		ray_object_intersection(t_ray ray, t_object object)
{
	t_intersection	ret_intersection;
	t_point			intersec_point;

	ret_intersection.ray = ray;
	ret_intersection.material = object.material;
	ret_intersection.t = ray_shape_intersection(ray, object);
	if ((ret_intersection.t < ray.t_max) && (ret_intersection.t > RAY_T_MIN))
	{
		intersec_point = calculate(ray, ret_intersection.t);
		ret_intersection.normal = point_shape_normal(intersec_point, object);
		ret_intersection.exist = 1;
	}
	else
		ret_intersection.exist = 0;
	return (ret_intersection);
}
