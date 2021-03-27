/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:01:07 by serma             #+#    #+#             */
/*   Updated: 2021/01/31 14:10:49 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "ray.h"
#include "vectormath.h"
#include <math.h>

static t_square_root	the_square_solve(t_ray ray, t_sphere sphere)
{
	t_vector		k;
	t_square_root	ret;
	t_vector		oc;

	oc = vec_sub((t_vector)(ray.origin), (t_vector)(sphere.center));
	k.x = vec_dot(ray.direction, ray.direction);
	k.y = 2 * vec_dot(oc, ray.direction);
	k.z = vec_dot(oc, oc) - sphere.r_square;
	ret = square_solve(k.x, k.y, k.z);
	return (ret);
}

double					ray_sphere_intersection(t_ray ray, t_sphere sphere)
{
	t_square_root	solve;

	solve = the_square_solve(ray, sphere);
	if (!solve.exist)
		return (-1);
	return (give_nearest_t(solve.root.x, solve.root.y));
}

t_vector				point_sphere_normal(t_point intersec_point,
		t_sphere sphere)
{
	t_vector	ret_normal;

	ret_normal = vec_sub((t_vector)(intersec_point), (t_vector)(sphere.center));
	ret_normal = vec_normalize(ret_normal);
	return (ret_normal);
}
