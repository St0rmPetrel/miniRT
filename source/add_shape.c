/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:05:31 by telman            #+#    #+#             */
/*   Updated: 2021/02/04 18:10:16 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_object.h"
#include "str_to_digit.h"
#include <math.h>
#include "scene.h"

int	add_sphere(char **words, t_scene *scene)
{
	t_object	*object;
	t_sphere	*sphere;

	if (!(object = create_object(words, IS_SPHERE)))
		return (1);
	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
	{
		free(object);
		return (1);
	}
	sphere->center = (t_point)ft_strtovec(words[1]);
	sphere->diameter = ft_strtod(words[2]);
	if (isnan((sphere->center).x * sphere->diameter))
	{
		free(object);
		free(sphere);
		return (1);
	}
	sphere->r_square = pow((sphere->diameter / 2), 2);
	object->data = (void *)sphere;
	add_in_scene((void *)object, scene, IS_OBJECT);
	return (0);
}

int	add_plane(char **words, t_scene *scene)
{
	t_object	*object;
	t_plane		*plane;

	if (!(object = create_object(words, IS_PLANE)))
		return (1);
	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
	{
		free(object);
		return (1);
	}
	plane->point = (t_point)ft_strtovec(words[1]);
	plane->normal = ft_strtovec(words[2]);
	if (isnan((plane->point).x * (plane->normal).x))
	{
		free(object);
		free(plane);
		return (1);
	}
	object->data = (void *)plane;
	add_in_scene((void *)object, scene, IS_OBJECT);
	return (0);
}

int	add_square(char **words, t_scene *scene)
{
	t_object	*object;
	t_square	*square;

	if (!(object = create_object(words, IS_SQUARE)))
		return (1);
	square = ft_calloc(1, sizeof(t_square));
	if (!square)
	{
		free(object);
		return (1);
	}
	square->center = (t_point)ft_strtovec(words[1]);
	square->normal = ft_strtovec(words[2]);
	square->size = ft_strtod(words[3]);
	if (isnan((square->center).x * (square->normal).x) * (square->size))
	{
		free(object);
		free(square);
		return (1);
	}
	object->data = (void *)square;
	add_in_scene((void *)object, scene, IS_OBJECT);
	return (0);
}

int	add_triangle(char **words, t_scene *scene)
{
	t_object	*object;
	t_triangle	*t;

	if (!(object = create_object(words, IS_TRIANGLE)))
		return (1);
	t = ft_calloc(1, sizeof(t_triangle));
	if (!t)
		free(object);
	if (!t)
		return (1);
	t->v0 = (t_point)ft_strtovec(words[1]);
	t->v1 = (t_point)ft_strtovec(words[2]);
	t->v2 = (t_point)ft_strtovec(words[3]);
	if (isnan((t->v0).x * (t->v1).x * (t->v2).x))
	{
		free(object);
		free(t);
		return (1);
	}
	t->edge_1 = vec_sub(t->v1, t->v0);
	t->edge_2 = vec_sub(t->v2, t->v0);
	t->normal = vec_normalize(vec_cross(t->edge_1, t->edge_2));
	object->data = (void *)t;
	add_in_scene((void *)object, scene, IS_OBJECT);
	return (0);
}

int	add_cylinder(char **words, t_scene *scene)
{
	t_object	*object;
	t_cylinder	*cylinder;

	if (!(object = create_object(words, IS_CYLINDER)))
		return (1);
	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		free(object);
	if (!cylinder)
		return (1);
	cylinder->center = (t_point)ft_strtovec(words[1]);
	cylinder->axis = ft_strtovec(words[2]);
	cylinder->diametr = ft_strtod(words[3]);
	cylinder->height = ft_strtod(words[4]);
	if (isnan((cylinder->center).x * (cylinder->axis).x * (cylinder->diametr) *
			(cylinder->height)))
	{
		free(object);
		free(cylinder);
		return (1);
	}
	cylinder->axis = vec_normalize(cylinder->axis);
	object->data = (void *)cylinder;
	add_in_scene((void *)object, scene, IS_OBJECT);
	return (0);
}
