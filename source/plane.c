/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:10:28 by serma             #+#    #+#             */
/*   Updated: 2021/01/14 12:17:48 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"
#include "ray.h"
#include "objects.h"

double		ray_plane_intersection(t_ray ray, t_plane plane)
{
	double	d_dot_n;
	double	ret_t;

	d_dot_n = vec_dot(ray.direction, plane.normal);
	if (d_dot_n == 0)
		return (-1);
	ret_t = vec_dot(vec_sub((t_vector)plane.point, (t_vector)ray.origin), \
			plane.normal) / d_dot_n;
	return (ret_t);
}

t_vector	point_plane_normal(t_plane plane)
{
	return (plane.normal);
}
