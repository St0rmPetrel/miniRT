/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:36:37 by serma             #+#    #+#             */
/*   Updated: 2021/01/12 17:11:55 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "objects.h"
# include "libft.h"
# include "ray.h"
# include "vectormath.h"

typedef struct		s_intersection
{
	t_ray		ray;
	t_vector	normal;
	t_material	material;
	double		t;
	int			exist;
}					t_intersection;

t_intersection		ray_scene_intersection(t_ray ray, t_list *objects);
t_intersection		ray_object_intersection(t_ray ray, t_object object);
int					ray_does_scene_intersection(t_ray ray, t_list *objects);

#endif
