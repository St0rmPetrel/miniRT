/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:18:39 by serma             #+#    #+#             */
/*   Updated: 2021/01/31 16:11:30 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "give.h"
#include "mlx.h"
#include "image.h"
#include "del_functions.h"

int		add_in_scene(void *object, t_scene *scene, int type)
{
	t_list	*object_node;

	object_node = ft_lstnew(object);
	if (object_node)
	{
		if (type == IS_CAMERA)
			ft_lstadd_front(&(scene->cameras), object_node);
		else if (type == IS_OBJECT)
			ft_lstadd_front(&(scene->objects), object_node);
		else if (type == IS_LIGHT)
			ft_lstadd_front(&(scene->lights), object_node);
		else
			free(object_node);
		return (0);
	}
	return (1);
}

void	free_scene(t_scene *scene)
{
	ft_lstclear(&(scene->objects), del_object);
	ft_lstclear(&(scene->lights), del_light);
	ft_lstclear(&(scene->cameras), del_camera);
	free(scene);
}
