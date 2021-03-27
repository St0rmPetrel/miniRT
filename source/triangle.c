/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:39:59 by serma             #+#    #+#             */
/*   Updated: 2021/01/31 14:07:51 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "ray.h"
#include "vectormath.h"
#include <math.h>

#include <stdio.h>

double			ray_triangle_intersection(t_ray ray, t_triangle triangle)
{
	t_vector	t_var;
	t_vector	q_var;
	t_vector	p_var;

	t_var = vec_sub((t_vector)ray.origin, (t_vector)triangle.v0);
	q_var = vec_cross(t_var, triangle.edge_1);
	p_var = vec_cross(ray.direction, triangle.edge_2);
	t_var = vec_mul(vec_set(vec_dot(q_var, triangle.edge_2),
				vec_dot(p_var, t_var),
				vec_dot(q_var, ray.direction)),
			1 / vec_dot(p_var, triangle.edge_1));
	if ((t_var.x >= RAY_T_MIN) && (t_var.y >= 0) && (t_var.z >= 0) &&
			((t_var.y + t_var.z) <= 1))
		return (t_var.x);
	return (-1);
}

t_vector		point_triangle_normal(t_triangle triangle)
{
	return (triangle.normal);
}
