/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:05:12 by telman            #+#    #+#             */
/*   Updated: 2021/02/01 16:33:11 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_add.h"
#include "str_to_digit.h"
#include <math.h>
#include "camera.h"
#include "vectormath.h"

int	add_camera(char **words, t_scene *scene)
{
	t_camera	*camera;

	if (len_of_array((void **)words) != 4)
		return (1);
	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		return (1);
	camera->origin = ft_strtovec(words[1]);
	camera->view = vec_normalize(ft_strtovec(words[2]));
	camera->fov = ft_strtod(words[3]);
	if (isnan((camera->origin).x * (camera->view).x * (camera->fov)))
	{
		free(camera);
		return (1);
	}
	if (add_in_scene((void *)camera, scene, IS_CAMERA))
	{
		free(camera);
		return (1);
	}
	return (0);
}

int	add_volume_object(char **words, t_scene *scene)
{
	char	*comand;
	int		is_error;

	is_error = 0;
	comand = words[0];
	if (ft_strncmp(comand, "sp", 3) == 0)
	{
		if (add_sphere(words, scene))
			is_error = 1;
	}
	else if (ft_strncmp(comand, "cy", 3) == 0)
	{
		if (add_cylinder(words, scene))
			is_error = 1;
	}
	else
		return (1);
	if (is_error)
		return (1);
	return (0);
}

int	add_flat_object(char **words, t_scene *scene)
{
	char	*comand;
	int		is_error;

	is_error = 0;
	comand = words[0];
	if (ft_strncmp(comand, "pl", 3) == 0)
	{
		if (add_plane(words, scene))
			is_error = 1;
	}
	else if (ft_strncmp(comand, "sq", 3) == 0)
	{
		if (add_square(words, scene))
			is_error = 1;
	}
	else if (ft_strncmp(comand, "tr", 3) == 0)
	{
		if (add_triangle(words, scene))
			is_error = 1;
	}
	else
		return (1);
	if (is_error)
		return (1);
	return (0);
}

int	add_object(char **words, t_scene *scene)
{
	char	*comand;
	int		is_error;

	is_error = 0;
	comand = words[0];
	if ((ft_strncmp(comand, "sp", 3) == 0) ||
			(ft_strncmp(comand, "cy", 3) == 0))
	{
		if (add_volume_object(words, scene))
			is_error = 1;
	}
	else if ((ft_strncmp(comand, "pl", 3) == 0) ||
				(ft_strncmp(comand, "sq", 3) == 0) ||
					(ft_strncmp(comand, "tr", 3) == 0))
	{
		if (add_flat_object(words, scene))
			is_error = 1;
	}
	else
		return (1);
	if (is_error)
		return (1);
	return (0);
}
