/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:06:35 by telman            #+#    #+#             */
/*   Updated: 2021/02/03 18:54:35 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_add.h"
#include "str_to_digit.h"
#include "objects.h"
#include <math.h>

int			degree_of_freedom(int type)
{
	if (type == IS_PLANE)
		return (2);
	else if (type == IS_SPHERE)
		return (2);
	else if (type == IS_TRIANGLE)
		return (3);
	else if (type == IS_CYLINDER)
		return (4);
	else if (type == IS_SQUARE)
		return (3);
	return (0);
}

t_material	set_material(char **words, int offset)
{
	t_material	material;

	material.color = ft_strtocolor(words[offset]);
	material.reflection = 0;
	material.refraction = 1;
	material.specular = 0;
	if (words[offset + 1])
	{
		material.specular = (int)ft_strtod(words[offset + 1]);
		if (words[offset + 2])
		{
			material.reflection = ft_strtod(words[offset + 2]);
			if (words[offset + 3])
				material.refraction = ft_strtod(words[offset + 3]);
		}
	}
	if (material.reflection > 1)
		material.reflection = 1;
	if (material.reflection < 0)
		material.reflection = 0;
	if (material.refraction <= 0)
		material.refraction = 0.00000000001;
	return (material);
}

t_object	*create_object(char **words, int type)
{
	t_object	*object;
	t_material	material;
	int			offset;
	int			len_of_params;

	offset = degree_of_freedom(type) + 1;
	len_of_params = len_of_array((void **)words);
	if (len_of_params <= degree_of_freedom(type) + 1)
		return (NULL);
	object = ft_calloc(1, sizeof(t_object));
	if (!object)
		return (NULL);
	object->type = type;
	material = set_material(words, offset);
	if ((isnan(material.specular * material.reflection * \
			material.refraction * material.color.r)) || \
				(material.color.r == -1))
	{
		free(object);
		return (NULL);
	}
	object->material = material;
	object->data = NULL;
	return (object);
}
