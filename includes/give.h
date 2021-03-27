/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 23:29:26 by telman            #+#    #+#             */
/*   Updated: 2021/01/27 17:26:35 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GIVE_H
# define GIVE_H

# include "ray.h"
# include "scene.h"
# include "camera.h"
# include "convas.h"

t_ray		give_ray(int x_convas, int y_convas, t_convas convas, \
		t_camera *camera);
int			give_pixel_color(int i, int j, t_camera *camera, t_scene *scene);
t_camera	*give_camera(t_scene scene, int camera_num);

#endif
