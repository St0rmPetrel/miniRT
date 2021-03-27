/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 23:18:37 by telman            #+#    #+#             */
/*   Updated: 2021/02/03 15:08:39 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "high_level_functions.h"
#include "scene.h"
#include "image.h"
#include "mlx.h"
#include "file_name_handler.h"
#include "hooks.h"
#include <errno.h>

static void	fill_draw_data(t_draw_data *data, char *file_name)
{
	void		*mlx_ptr;
	t_image		*image;
	t_scene		*scene;

	mlx_ptr = mlx_init();
	scene = read_scene(mlx_ptr, file_name);
	image = create_new_image(mlx_ptr, scene->convas);
	data->current_camera = 1;
	data->image = image;
	data->scene = scene;
	data->is_caps = 0;
	data->mlx_ptr = mlx_ptr;
	draw_scene_in_image(image, scene, data->current_camera);
}

static void	loop_hook(t_draw_data draw_data)
{
	mlx_key_hook(draw_data.win_ptr, key_hook, &draw_data);
	mlx_hook(draw_data.win_ptr, 2, 1L << 0, key_push_hook, &draw_data);
	mlx_hook(draw_data.win_ptr, 17, 0, exit_and_free, &draw_data);
	mlx_loop(draw_data.mlx_ptr);
}

int			main(int argc, char **argv)
{
	t_draw_data	draw_data;

	if ((argc < 2) || (argc > 3))
		error_messege("Invalid number of arguments", 0);
	if (is_invalid_filename(argv[1]))
		error_messege("Invalie scena file name", 0);
	fill_draw_data(&draw_data, argv[1]);
	if ((argc == 3) && (!ft_strncmp(argv[2], "--save", 6)))
	{
		save_image(draw_data.image, draw_data.scene->convas, argv[1]);
		free_scene(draw_data.scene);
		mlx_destroy_image(draw_data.mlx_ptr, draw_data.image->img);
		return (0);
	}
	else if (argc == 3)
		error_messege("Invalid second argument", 0);
	draw_data.win_ptr = mlx_new_window(draw_data.mlx_ptr,
			draw_data.scene->convas.width,
			draw_data.scene->convas.hight, "miniRT");
	mlx_put_image_to_window(draw_data.mlx_ptr, draw_data.win_ptr,
			draw_data.image->img, 0, 0);
	loop_hook(draw_data);
	return (0);
}
