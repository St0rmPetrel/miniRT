/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_does_scene_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:05:22 by serma             #+#    #+#             */
/*   Updated: 2021/01/11 15:10:57 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "libft.h"

int		ray_does_scene_intersection(t_ray ray, t_list *objects)
{
	t_intersection	current_intersection;

	while (objects)
	{
		current_intersection = ray_object_intersection(ray, \
				*(t_object *)(objects->content));
		if (current_intersection.exist)
			return (1);
		objects = objects->next;
	}
	return (0);
}
