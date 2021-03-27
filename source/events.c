/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:49:34 by serma             #+#    #+#             */
/*   Updated: 2021/02/03 15:12:44 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_handler.h"
#include "events.h"
#include "mlx.h"
#include "libft.h"
#include "give.h"

void	change_caps(t_draw_data *data)
{
	if (data->is_caps == 0)
		data->is_caps = 1;
	else
		data->is_caps = 0;
}

void	redraw(t_draw_data *data)
{
	draw_scene_in_image(data->image, data->scene, data->current_camera);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image->img, 0, 0);
}

void	change_camera(t_draw_data *data)
{
	int		count_of_cameras;

	count_of_cameras = ft_lstsize(data->scene->cameras);
	data->current_camera = (data->current_camera + 1) % count_of_cameras;
	if (data->current_camera == 0)
		data->current_camera = count_of_cameras;
	redraw(data);
}

void	camera_move(t_draw_data *data, int coordinate, double factor)
{
	t_camera	*camera;
	t_vector	delta;

	camera = give_camera(*(data->scene), data->current_camera);
	if (coordinate == 0)
		delta = (camera->crd).basis.x;
	else if (coordinate == 1)
		delta = (camera->crd).basis.y;
	else if (coordinate == 2)
		delta = (camera->crd).basis.z;
	else
	{
		delta = (camera->crd).basis.x;
		factor = 0;
	}
	delta = vec_mul(delta, factor);
	camera->origin = vec_add((t_vector)camera->origin, delta);
	redraw(data);
}

void	camera_rotation(t_draw_data *data, int coordinate, double factor)
{
	t_camera	*camera;
	t_vector	axis;

	camera = give_camera(*(data->scene), data->current_camera);
	if (coordinate == 0)
		axis = (camera->crd).basis.x;
	else if (coordinate == 1)
		axis = (camera->crd).basis.y;
	else if (coordinate == 2)
		axis = (camera->crd).basis.z;
	else
	{
		axis = (camera->crd).basis.x;
		factor = 0;
	}
	camera->view = vec_rotate(camera->view, axis, factor);
	camera->view = vec_normalize(camera->view);
	redraw(data);
}
