/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormath_vec3_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:32:23 by serma             #+#    #+#             */
/*   Updated: 2021/01/12 17:25:01 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"
#include <math.h>

t_vector		vec_div(t_vector v1, double t)
{
	t_vector	v_ret;

	v_ret.x = v1.x / t;
	v_ret.y = v1.y / t;
	v_ret.z = v1.z / t;
	return (v_ret);
}

double			vec_length(t_vector v1)
{
	double	ret;

	ret = sqrt(pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2));
	return (ret);
}

double			vec_length2(t_vector v1)
{
	double	ret;

	ret = pow(v1.x, 2) + pow(v1.y, 2) + pow(v1.z, 2);
	return (ret);
}

t_vector		vec_normalize(t_vector v1)
{
	double		len;
	t_vector	v_ret;

	len = vec_length(v1);
	if (len == 0)
		return (vec_set(0, 0, 0));
	v_ret = vec_div(v1, len);
	return (v_ret);
}

t_vector		vec_set(double x, double y, double z)
{
	t_vector	ret_vector;

	ret_vector.x = x;
	ret_vector.y = y;
	ret_vector.z = z;
	return (ret_vector);
}
