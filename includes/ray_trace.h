/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:03:04 by serma             #+#    #+#             */
/*   Updated: 2021/01/27 17:02:47 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACE_H
# define RAY_TRACE_H

# include "colors.h"
# include "scene.h"
# include "intersection.h"

t_color			ray_trace(t_ray ray, t_scene *scene);
t_ray			ray_reflect(t_ray ray, t_intersection hit);
t_ray			ray_refract(t_ray ray, t_intersection hit);

#endif
