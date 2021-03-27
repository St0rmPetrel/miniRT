/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:24:32 by serma             #+#    #+#             */
/*   Updated: 2021/01/25 18:20:37 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vectormath.h"
# include "colors.h"

# define AMBIENT_LIGHT 0
# define POINT_LIGHT 1
# define DIRECT_LIGHT 2

typedef struct	s_light
{
	int		type;
	void	*data;
	double	intensity;
	t_color	color;
}				t_light;

typedef struct	s_point_light
{
	t_point	center;
}				t_point_light;

typedef struct	s_direct_light
{
	t_vector	direction;
}				t_direct_light;

#endif
