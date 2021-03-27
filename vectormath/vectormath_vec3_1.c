/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormath_vec3_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:02:33 by serma             #+#    #+#             */
/*   Updated: 2021/01/06 15:27:52 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"

t_vector		vec_add(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.x + v2.x;
	v_ret.y = v1.y + v2.y;
	v_ret.z = v1.z + v2.z;
	return (v_ret);
}

t_vector		vec_sub(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.x - v2.x;
	v_ret.y = v1.y - v2.y;
	v_ret.z = v1.z - v2.z;
	return (v_ret);
}

double			vec_dot(t_vector v1, t_vector v2)
{
	double	ret;

	ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (ret);
}

t_vector		vec_cross(t_vector v1, t_vector v2)
{
	t_vector	v_ret;

	v_ret.x = v1.y * v2.z - v1.z * v2.y;
	v_ret.y = v1.z * v2.x - v1.x * v2.z;
	v_ret.z = v1.x * v2.y - v1.y * v2.x;
	return (v_ret);
}

t_vector		vec_mul(t_vector v1, double t)
{
	t_vector	v_ret;

	v_ret.x = v1.x * t;
	v_ret.y = v1.y * t;
	v_ret.z = v1.z * t;
	return (v_ret);
}
