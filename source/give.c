/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:28:33 by serma             #+#    #+#             */
/*   Updated: 2021/02/03 17:11:55 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"
#include <math.h>
#include "ray.h"
#include "camera.h"
#include "scene.h"
#include "colors.h"
#include "ray_trace.h"

#include <stdio.h>

t_coordinate_system	give_camera_coordinate_system(t_convas convas,
		t_camera camera)
{
	double				val;
	t_vector			up_dir;
	t_coordinate_system	ret_crd_sys;

	val = PI / 180;
	up_dir = vec_set(0, 0, 1);
	ret_crd_sys.distance = ((double)(convas.width)) / (camera.fov * val);
	ret_crd_sys.basis.z = camera.view;
	ret_crd_sys.basis.y = vec_normalize(vec_cross(up_dir, camera.view));
	if (is_null_vec(ret_crd_sys.basis.y))
		ret_crd_sys.basis.y = vec_set(0, -1, 0);
	ret_crd_sys.basis.x = vec_cross(ret_crd_sys.basis.y, ret_crd_sys.basis.z);
	return (ret_crd_sys);
}

t_ray				give_ray(int x_convas, int y_convas, t_convas convas, \
									t_camera *camera)
{
	t_ray					ret_ray;
	double					gamma;
	t_vector				teta;
	t_vector				local_coord;

	ret_ray.origin = camera->origin;
	ret_ray.t_max = RAY_T_MAX;
	ret_ray.refl_deep = 0;
	ret_ray.refr_deep = 0;
	local_coord.x = (double)(y_convas) - ((double)convas.hight) / 2;
	local_coord.y = -(double)(x_convas) + ((double)convas.width) / 2;
	local_coord.z = (camera->crd).distance;
	teta = vec_add(vec_mul((camera->crd).basis.x, local_coord.x),
			vec_mul((camera->crd).basis.y, local_coord.y));
	gamma = vec_length(teta) / (camera->crd).distance;
	ret_ray.direction = vec_add(vec_mul((camera->crd).basis.z, \
				cos(gamma) * ((camera->crd).distance)), \
		vec_mul(vec_normalize(teta), sin(gamma) * (camera->crd).distance));
	ret_ray.direction = vec_normalize(ret_ray.direction);
	return (ret_ray);
}

int					give_pixel_color(int i, int j, t_camera *camera, \
		t_scene *scene)
{
	t_ray	ray;
	t_color	color;

	ray = give_ray(i, j, scene->convas, camera);
	color = ray_trace(ray, scene);
	return (color_to_int(color));
}

t_camera			*give_camera(t_scene scene, int camera_num)
{
	int	count_of_cameras;
	int	index_of_camera;
	int	counter;

	count_of_cameras = ft_lstsize(scene.cameras);
	if (camera_num > count_of_cameras)
		return (NULL);
	index_of_camera = count_of_cameras - camera_num;
	counter = 0;
	while ((scene.cameras) && (counter < index_of_camera))
	{
		counter++;
		scene.cameras = (scene.cameras)->next;
	}
	return ((scene.cameras)->content);
}
