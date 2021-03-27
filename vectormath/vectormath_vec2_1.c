/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormath_vec2_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:03:50 by serma             #+#    #+#             */
/*   Updated: 2021/01/06 16:07:21 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"

t_vector2		vec2_add(t_vector2 v1, t_vector2 v2)
{
	t_vector2	v_ret;

	v_ret.x = v1.x + v2.x;
	v_ret.y = v1.y + v2.y;
	return (v_ret);
}

t_vector2		vec2_sub(t_vector2 v1, t_vector2 v2)
{
	t_vector2	v_ret;

	v_ret.x = v1.x - v2.x;
	v_ret.y = v1.y - v2.y;
	return (v_ret);
}

double			vec2_dot(t_vector2 v1, t_vector2 v2)
{
	double	ret;

	ret = v1.x * v2.x + v1.y * v2.y;
	return (ret);
}

t_vector2		vec2_mul(t_vector2 v1, double t)
{
	t_vector2	v_ret;

	v_ret.x = v1.x * t;
	v_ret.y = v1.y * t;
	return (v_ret);
}
