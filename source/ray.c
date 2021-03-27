/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:57:30 by serma             #+#    #+#             */
/*   Updated: 2021/01/31 14:12:49 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vectormath.h"

t_point	calculate(t_ray ray, double t)
{
	t_point	ret_point;

	ret_point = (t_point)vec_add((t_vector)(ray.origin), \
			vec_mul(ray.direction, t));
	return (ret_point);
}

double	give_nearest_t(double t_1, double t_2)
{
	if ((t_1 > RAY_T_MIN) && (t_2 > RAY_T_MIN))
		return ((t_1 > t_2) ? t_2 : t_1);
	else if (t_1 > RAY_T_MIN)
		return (t_1);
	else if (t_2 > RAY_T_MIN)
		return (t_2);
	return (-1);
}
