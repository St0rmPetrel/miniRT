/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:40:50 by serma             #+#    #+#             */
/*   Updated: 2021/01/31 13:26:38 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vectormath.h"
# define RAY_T_MIN 0.000001
# define RAY_T_MAX 1.0e30f
# define MAX_REFL_DEEP 3
# define MAX_REFR_DEEP 6

typedef struct	s_ray
{
	t_vector	direction;
	t_point		origin;
	double		t_max;
	int			refl_deep;
	int			refr_deep;
}				t_ray;

t_point			calculate(t_ray ray, double t);
double			give_nearest_t(double t_1, double t_2);

#endif
