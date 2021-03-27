/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:52:12 by serma             #+#    #+#             */
/*   Updated: 2021/01/25 19:05:49 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_add.h"
#include "str_to_digit.h"
#include <math.h>
#include "light.h"
#include "camera.h"

int	set_resolution(char **words, t_scene *scene)
{
	t_convas	convas;

	if (len_of_array((void **)words) != 3)
		return (1);
	convas.width = ft_atoi(words[1]);
	convas.hight = ft_atoi(words[2]);
	if ((convas.width <= 0) || (convas.hight <= 0))
		return (1);
	scene->convas = convas;
	return (0);
}

int	set_ambient_lightning(char **words, t_scene *scene)
{
	t_light	*ambient_light;
	int		len_of_comand;

	len_of_comand = len_of_array((void **)words);
	if (len_of_comand != 3)
		return (1);
	ambient_light = ft_calloc(1, sizeof(t_light));
	if (!ambient_light)
		return (1);
	ambient_light->intensity = ft_strtod(words[1]);
	ambient_light->color = ft_strtocolor(words[2]);
	if (isnan(ambient_light->intensity) || ((ambient_light->color).r == -1))
	{
		free(ambient_light);
		return (1);
	}
	ambient_light->type = AMBIENT_LIGHT;
	ambient_light->data = NULL;
	if (add_in_scene((void *)ambient_light, scene, IS_LIGHT))
	{
		free(ambient_light);
		return (1);
	}
	return (0);
}
