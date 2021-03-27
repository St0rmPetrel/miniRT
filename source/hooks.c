/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:01:39 by serma             #+#    #+#             */
/*   Updated: 2021/02/01 16:39:04 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
#include "mlx.h"
#include "events.h"

int		exit_and_free(t_draw_data *data)
{
	free_scene(data->scene);
	if (data->image)
		mlx_destroy_image(data->mlx_ptr, data->image->img);
	data->image = NULL;
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	exit(0);
}

void	camera_some_move(int keycode, t_draw_data *data)
{
	if (keycode == 48)
		change_camera(data);
	else if (keycode == 49)
		camera_move(data, 0, -1);
	else if (keycode == 257)
		camera_move(data, 0, 1);
	else if (keycode == 2)
		camera_move(data, 1, -1);
	else if (keycode == 0)
		camera_move(data, 1, 1);
	else if (keycode == 13)
		camera_move(data, 2, 1);
	else if (keycode == 1)
		camera_move(data, 2, -1);
}

void	camera_some_rotation(int keycode, t_draw_data *data)
{
	if (keycode == 48)
		change_camera(data);
	else if (keycode == 2)
		camera_rotation(data, 0, 10);
	else if (keycode == 0)
		camera_rotation(data, 0, -10);
	else if (keycode == 13)
		camera_rotation(data, 1, -10);
	else if (keycode == 1)
		camera_rotation(data, 1, 10);
}

int		key_hook(int keycode, t_draw_data *data)
{
	if (keycode == 53)
		exit_and_free(data);
	else if (((keycode == 48) || (keycode == 49) || (keycode == 257) ||
				(keycode == 2) || (keycode == 0) || (keycode == 13) ||
					(keycode == 1)) && !(data->is_caps))
		camera_some_move(keycode, data);
	else if (((keycode == 48) || (keycode == 49) || (keycode == 257) ||
				(keycode == 2) || (keycode == 0) || (keycode == 13) ||
					(keycode == 1)) && (data->is_caps))
		camera_some_rotation(keycode, data);
	else if (keycode == 272)
		change_caps(data);
	return (0);
}

int		key_push_hook(int keycode, t_draw_data *data)
{
	if (keycode == 272)
		change_caps(data);
	return (0);
}
