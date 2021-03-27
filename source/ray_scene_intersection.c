/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_scene_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:07:08 by serma             #+#    #+#             */
/*   Updated: 2021/01/31 14:08:59 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"
#include "libft.h"

t_intersection		ray_scene_intersection(t_ray ray, t_list *objects)
{
	t_intersection	ret_intersection;
	t_intersection	temp_intersection;

	ret_intersection.ray = ray;
	ret_intersection.exist = 0;
	while (objects)
	{
		temp_intersection = ray_object_intersection(ray, \
				*(t_object *)(objects->content));
		if ((!ret_intersection.exist) && (temp_intersection.exist))
			ret_intersection = temp_intersection;
		else if ((temp_intersection.exist) && (ret_intersection.exist) && \
			(temp_intersection.t < ret_intersection.t))
			ret_intersection = temp_intersection;
		objects = objects->next;
	}
	if ((ret_intersection.exist) &&
			(vec_dot(ret_intersection.normal,
				ret_intersection.ray.direction) > 0))
		ret_intersection.normal = vec_mul(ret_intersection.normal, -1);
	return (ret_intersection);
}
