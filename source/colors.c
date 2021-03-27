/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:48:05 by serma             #+#    #+#             */
/*   Updated: 2021/01/25 18:16:42 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_color	color_set(int r, int g, int b, double alpha)
{
	t_color	ret_color;

	if ((r <= RED_MAX) && (r >= 0))
		ret_color.r = r;
	else
		ret_color.r = (r > RED_MAX) ? RED_MAX : 0;
	if ((g <= GREEN_MAX) && (g >= 0))
		ret_color.g = g;
	else
		ret_color.g = (g > GREEN_MAX) ? GREEN_MAX : 0;
	if ((b <= BLUE_MAX) && (b >= 0))
		ret_color.b = b;
	else
		ret_color.b = (b > BLUE_MAX) ? BLUE_MAX : 0;
	if ((alpha <= 1) && (alpha >= 0))
		ret_color.alpha = alpha;
	else
		ret_color.alpha = (alpha > 1) ? 1 : 0;
	return (ret_color);
}

t_color	color_add(t_color color1, t_color color2)
{
	t_color	ret_color;

	ret_color.r = color1.r + color2.r;
	if (ret_color.r > RED_MAX)
		ret_color.r = RED_MAX;
	ret_color.g = color1.g + color2.g;
	if (ret_color.g > GREEN_MAX)
		ret_color.g = GREEN_MAX;
	ret_color.b = color1.b + color2.b;
	if (ret_color.b > BLUE_MAX)
		ret_color.b = BLUE_MAX;
	ret_color.alpha = color1.alpha * color2.alpha;
	return (ret_color);
}

t_color	color_mul(t_color color, double t)
{
	t_color	ret_color;

	ret_color.r = color.r * t;
	if (ret_color.r > RED_MAX)
		ret_color.r = RED_MAX;
	ret_color.g = color.g * t;
	if (ret_color.g > GREEN_MAX)
		ret_color.g = GREEN_MAX;
	ret_color.b = color.b * t;
	if (ret_color.b > BLUE_MAX)
		ret_color.b = BLUE_MAX;
	ret_color.alpha = color.alpha;
	return (ret_color);
}

t_color	color_vector_mul(t_color color, t_vector v)
{
	t_color	ret_color;

	ret_color.r = color.r * v.x;
	if (ret_color.r > RED_MAX)
		ret_color.r = RED_MAX;
	ret_color.g = color.g * v.y;
	if (ret_color.g > GREEN_MAX)
		ret_color.g = GREEN_MAX;
	ret_color.b = color.b * v.z;
	if (ret_color.b > BLUE_MAX)
		ret_color.b = BLUE_MAX;
	ret_color.alpha = color.alpha;
	return (ret_color);
}

int		color_to_int(t_color color)
{
	return (256 * 256 * color.r + 256 * color.g + color.b);
}
