/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:35:40 by serma             #+#    #+#             */
/*   Updated: 2021/02/03 15:03:25 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "ray.h"
#include "vectormath.h"
#include <math.h>

static t_square_root	the_square_solve(t_ray ray, t_cylinder cylinder)
{
	t_vector		k;
	t_vector		oc;
	t_square_root	ret;

	oc = vec_sub((t_vector)(ray.origin), (t_vector)(cylinder.center));
	k.x = vec_dot(ray.direction, ray.direction) -
		pow(vec_dot(cylinder.axis, ray.direction), 2);
	k.y = 2 * vec_dot(oc, ray.direction) - 2 * vec_dot(cylinder.axis,
			oc) * vec_dot(cylinder.axis, ray.direction);
	k.z = vec_dot(oc, oc) - pow(vec_dot(cylinder.axis, oc), 2) -
		pow(cylinder.diametr / 2, 2);
	ret = square_solve(k.x, k.y, k.z);
	return (ret);
}

double					ray_cylinder_intersection(t_ray ray,
		t_cylinder cylinder)
{
	t_square_root	solve;
	t_vector		c_s1;
	t_vector		c_s2;
	double			dot;

	solve = the_square_solve(ray, cylinder);
	if (!solve.exist)
		return (-1);
	c_s1 = vec_sub(calculate(ray, solve.root.x), cylinder.center);
	c_s2 = vec_sub(calculate(ray, solve.root.y), cylinder.center);
	dot = vec_dot(c_s1, cylinder.axis);
	if ((dot < -cylinder.height / 2) || (dot > cylinder.height / 2))
		solve.root.x = -1;
	dot = vec_dot(c_s2, cylinder.axis);
	if ((dot < -cylinder.height / 2) || (dot > cylinder.height / 2))
		solve.root.y = -1;
	return (give_nearest_t(solve.root.x, solve.root.y));
}

t_vector				point_cylinder_normal(t_point intersec_point,
		t_cylinder cylinder)
{
	t_vector	ret_normal;
	t_vector	v;
	t_vector	op;

	op = vec_sub((t_vector)intersec_point, (t_vector)(cylinder.center));
	v = vec_cross(op, cylinder.axis);
	ret_normal = vec_cross(v, cylinder.axis);
	ret_normal = vec_normalize(ret_normal);
	return (ret_normal);
}
