/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:16:50 by serma             #+#    #+#             */
/*   Updated: 2021/01/27 17:06:33 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "intersection.h"
# include "scene.h"
# include "colors.h"
# include "light.h"

t_color	lighting_color(t_intersection hit, t_scene scene);

t_color	ambient_lighting(t_intersection hit, t_light light);
t_color	point_lighting(t_intersection hit, t_light light, t_list *objects);
t_color	direct_lighting(t_intersection hit, t_light light, t_list *objects);
t_color	give_color(t_color material_color, t_color light_color,
						double light_intensity);

#endif
