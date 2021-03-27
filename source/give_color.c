/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:29:24 by serma             #+#    #+#             */
/*   Updated: 2021/01/26 12:55:14 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"
#include "vectormath.h"

t_vector	give_vec_intensity(t_color color, double intensity)
{
	t_vector	ret;

	ret.x = ((double)color.r / 255) * intensity;
	ret.y = ((double)color.g / 255) * intensity;
	ret.z = ((double)color.b / 255) * intensity;
	return (ret);
}

t_color		give_color(t_color material_color, t_color light_color,
		double light_intensity)
{
	t_vector	intensity;
	t_color		ret_color;

	intensity = give_vec_intensity(light_color, light_intensity);
	ret_color = color_vector_mul(material_color, intensity);
	return (ret_color);
}
