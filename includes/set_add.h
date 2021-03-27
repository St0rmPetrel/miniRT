/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_add.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:11:58 by serma             #+#    #+#             */
/*   Updated: 2021/01/28 18:25:11 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ADD_H
# define SET_ADD_H

# include "scene.h"

int	set_resolution(char **words, t_scene *scene);
int	set_ambient_lightning(char **words, t_scene *scene);

int	add_camera(char **words, t_scene *scene);

int	add_light(char **words, t_scene *scene);
int	add_direction_light(char **words, t_scene *scene);
int	add_point_light(char **words, t_scene *scene);

int	add_object(char **words, t_scene *scene);
int	add_sphere(char **words, t_scene *scene);
int	add_plane(char **words, t_scene *scene);
int	add_square(char **words, t_scene *scene);
int	add_triangle(char **words, t_scene *scene);
int	add_cylinder(char **words, t_scene *scene);

#endif
