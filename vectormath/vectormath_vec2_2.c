/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormath_vec2_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:07:33 by serma             #+#    #+#             */
/*   Updated: 2021/01/06 16:15:31 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"
#include <math.h>

t_vector2		vec2_div(t_vector2 v1, double t)
{
	t_vector2	v_ret;

	v_ret.x = v1.x / t;
	v_ret.y = v1.y / t;
	return (v_ret);
}

double			vec2_length(t_vector2 v1)
{
	double	ret;

	ret = sqrt(pow(v1.x, 2) + pow(v1.y, 2));
	return (ret);
}

double			vec2_length2(t_vector2 v1)
{
	double	ret;

	ret = pow(v1.x, 2) + pow(v1.y, 2);
	return (ret);
}

t_vector2		vec2_normalize(t_vector2 v1)
{
	double		len;
	t_vector2	v_ret;

	len = vec2_length(v1);
	v_ret = vec2_div(v1, len);
	return (v_ret);
}
