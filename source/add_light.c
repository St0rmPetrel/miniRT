/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:30:11 by serma             #+#    #+#             */
/*   Updated: 2021/01/25 18:27:59 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_add.h"
#include "str_to_digit.h"
#include <math.h>
#include "light.h"

static void		free_light(t_light *light)
{
	free(light->data);
	free(light);
}

static t_light	*create_light(char **words, int type)
{
	t_light	*light;
	int		len_of_command;

	len_of_command = len_of_array((void **)words);
	if (len_of_command != 4)
		return (NULL);
	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		return (NULL);
	light->intensity = ft_strtod(words[2]);
	light->color = ft_strtocolor(words[3]);
	if (isnan(light->intensity) || ((light->color).r == -1))
	{
		free(light);
		return (NULL);
	}
	light->type = type;
	light->data = NULL;
	return (light);
}

int				add_direction_light(char **words, t_scene *scene)
{
	t_light	*light;
	void	*data;
	int		is_error;

	is_error = 0;
	light = create_light(words, DIRECT_LIGHT);
	if (!light)
		return (1);
	if (!(data = ft_calloc(1, sizeof(t_point_light))))
		return (1);
	((t_direct_light *)data)->direction = ft_strtovec(words[1]);
	if (isnan(light->intensity * \
				(((t_direct_light *)data)->direction).x))
		is_error = 1;
	light->data = data;
	if (add_in_scene((void *)light, scene, IS_LIGHT))
		is_error = 1;
	if (is_error)
	{
		free_light(light);
		return (1);
	}
	return (0);
}

int				add_point_light(char **words, t_scene *scene)
{
	t_light	*light;
	void	*data;
	int		is_error;

	is_error = 0;
	light = create_light(words, POINT_LIGHT);
	if (!light)
		return (1);
	if (!(data = ft_calloc(1, sizeof(t_point_light))))
		return (1);
	((t_point_light *)data)->center = ft_strtovec(words[1]);
	if (isnan(light->intensity * \
				(((t_point_light *)data)->center).x))
		is_error = 1;
	light->data = data;
	if (add_in_scene((void *)light, scene, IS_LIGHT))
		is_error = 1;
	if (is_error)
	{
		free_light(light);
		return (1);
	}
	return (0);
}

int				add_light(char **words, t_scene *scene)
{
	char	*comand;
	int		is_error;

	is_error = 0;
	comand = words[0];
	if (ft_strncmp(comand, "ld", 3) == 0)
	{
		if (add_direction_light(words, scene))
			is_error = 1;
	}
	else if ((ft_strncmp(comand, "lp", 3) == 0) || \
				(ft_strncmp(comand, "l", 2) == 0))
	{
		if (add_point_light(words, scene))
			is_error = 1;
	}
	else
		return (1);
	return (0);
}
