/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:25:21 by serma             #+#    #+#             */
/*   Updated: 2021/02/04 12:21:53 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_to_digit.h"
#include "libft.h"
#include "split_handler.h"
#include <math.h>

double		int_part_tod(const char *int_part)
{
	double	ret;

	if (!int_part)
		return (NAN);
	if (!(ft_isdigit(*int_part)) && (*int_part != '-'))
		return (NAN);
	ret = ft_atoi(int_part);
	return (ret);
}

double		fraction_part_tod(const char *fraction_part)
{
	double	ret;
	double	int_p;

	if (!fraction_part)
		return (NAN);
	int_p = int_part_tod(fraction_part);
	if (int_p < 0)
		return (NAN);
	ret = int_p / pow(10, (double)ft_strlen(fraction_part));
	return (ret);
}

double		ft_strtod(const char *str)
{
	char	**parts;
	double	ret;
	double	int_part;
	double	fraction_part;

	if (!ft_strchr(str, '.'))
		return (int_part_tod(str));
	parts = ft_split(str, '.');
	int_part = int_part_tod(parts[0]);
	fraction_part = fraction_part_tod(parts[1]);
	if ((int_part > 0) || ((int_part == 0) && (*str != '-')))
		ret = int_part + fraction_part;
	else
		ret = int_part - fraction_part;
	free_array((void **)parts);
	return (ret);
}

t_vector	ft_strtovec(const char *str)
{
	t_vector	ret;
	char		**dimensions;

	ret.x = NAN;
	ret.y = NAN;
	ret.z = NAN;
	dimensions = ft_split(str, ',');
	if (!dimensions)
		return (ret);
	if (len_of_array((void **)dimensions) == 3)
	{
		ret.x = ft_strtod(dimensions[0]);
		ret.y = ft_strtod(dimensions[1]);
		ret.z = ft_strtod(dimensions[2]);
	}
	free_array((void **)dimensions);
	if (isnan(ret.x * ret.y * ret.z))
		ret.x = NAN;
	return (ret);
}

t_color		ft_strtocolor(const char *str)
{
	t_color	ret;
	char	**dimensions;
	int		len_of_dim;

	ft_bzero((void *)(&ret), sizeof(t_color));
	ret.r = -1;
	dimensions = ft_split(str, ',');
	if (!dimensions)
		return (ret);
	len_of_dim = len_of_array((void **)(dimensions));
	if ((len_of_dim == 3) || (len_of_dim == 4))
	{
		ret.r = ft_atoi(dimensions[0]);
		ret.g = ft_atoi(dimensions[1]);
		ret.b = ft_atoi(dimensions[2]);
		if (len_of_dim == 4)
			ret.alpha = ft_strtod(dimensions[3]);
	}
	free_array((void **)dimensions);
	if ((ret.r < 0) || (ret.g < 0) || (ret.b < 0) ||
			(ret.r > 255) || (ret.g > 255) || (ret.b > 255) ||
			(ret.alpha < 0) || (ret.alpha > 1))
		ret.r = -1;
	return (ret);
}
