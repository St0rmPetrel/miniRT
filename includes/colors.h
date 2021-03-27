/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:39:18 by serma             #+#    #+#             */
/*   Updated: 2021/01/25 18:45:58 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "vectormath.h"

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
	double	alpha;
}				t_color;

t_color			color_add(t_color color1, t_color color2);
t_color			color_mul(t_color color, double t);
t_color			color_vector_mul(t_color color, t_vector v);
t_color			color_set(int r, int g, int b, double alpha);
int				color_to_int(t_color color);

# define BACK_GROUND_COLOR color_set(0, 0, 0, 0)

# define RED_MAX 255
# define GREEN_MAX 255
# define BLUE_MAX 255

#endif
