/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:13:51 by serma             #+#    #+#             */
/*   Updated: 2021/01/31 14:05:51 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"
#include "objects.h"

double			ray_square_intersection(t_ray ray, t_square square)
{
	double		ret;
	double		dot[2];
	t_plane		plane;
	t_vector	v[3];

	plane.point = square.center;
	plane.normal = square.normal;
	ret = ray_plane_intersection(ray, plane);
	if (!ret)
		return (0);
	v[0] = vec_cross(vec_set(0, 0, 1), square.normal);
	if (((v[0]).x == 0) && ((v[0]).y == 0) && ((v[0]).z == 0))
		v[0] = vec_set(0, 1, 0);
	else
		v[0] = vec_normalize(v[0]);
	v[1] = vec_cross(v[0], square.normal);
	v[2] = vec_sub((t_vector)calculate(ray, ret), (t_vector)square.center);
	dot[0] = vec_dot(v[0], v[2]);
	dot[1] = vec_dot(v[1], v[2]);
	if ((dot[0] <= (square.size / 2)) && (dot[0] >= (-square.size / 2)) &&
			(dot[1] <= (square.size / 2)) && (dot[1] >= (-square.size / 2)))
		return (ret);
	return (0);
}

t_vector		point_square_normal(t_square square)
{
	return (square.normal);
}
