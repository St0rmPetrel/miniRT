/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormath_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:41:21 by serma             #+#    #+#             */
/*   Updated: 2021/02/04 19:37:13 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"
#include <math.h>

t_matrix	give_rotate_matrix(t_vector axis, double teta)
{
	t_matrix	ret;

	teta = teta * (PI / 180);
	ret.x.x = cos(teta) + (1 - cos(teta)) * pow(axis.x, 2);
	ret.x.y = (1 - cos(teta)) * axis.x * axis.y - sin(teta) * axis.z;
	ret.x.z = (1 - cos(teta)) * axis.x * axis.z + sin(teta) * axis.y;
	ret.y.x = (1 - cos(teta)) * axis.y * axis.x + sin(teta) * axis.z;
	ret.y.y = cos(teta) + (1 - cos(teta)) * pow(axis.y, 2);
	ret.y.z = (1 - cos(teta)) * axis.y * axis.z - sin(teta) * axis.x;
	ret.z.x = (1 - cos(teta)) * axis.z * axis.x - sin(teta) * axis.y;
	ret.z.y = (1 - cos(teta)) * axis.z * axis.y + sin(teta) * axis.x;
	ret.z.z = cos(teta) + (1 - cos(teta)) * pow(axis.z, 2);
	return (ret);
}

t_vector	matrix_mul_vec(t_matrix matrix, t_vector v)
{
	t_vector	ret;

	ret.x = ((matrix.x.x) * (v.x)) + ((matrix.x.y) * (v.y)) +
						((matrix.x.z) * (v.z));
	ret.y = ((matrix.y.x) * (v.x)) + ((matrix.y.y) * (v.y)) +
						((matrix.y.z) * (v.z));
	ret.z = ((matrix.z.x) * (v.x)) + ((matrix.z.y) * (v.y)) +
						((matrix.z.z) * (v.z));
	return (ret);
}

t_vector	vec_rotate(t_vector v, t_vector axis, double teta)
{
	t_matrix	m;

	m = give_rotate_matrix(axis, teta);
	return (matrix_mul_vec(m, v));
}
