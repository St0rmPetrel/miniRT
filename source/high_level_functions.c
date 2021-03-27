/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_level_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:21:51 by serma             #+#    #+#             */
/*   Updated: 2021/01/26 12:57:41 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "high_level_functions.h"
#include "save_image.h"
#include "parser.h"
#include "file_name_handler.h"
#include "libft.h"
#include <mlx.h>
#include <errno.h>

void	error_messege(char *err_msg, int my_errno)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(": ", 2);
	if (my_errno)
		ft_putstr_fd(strerror(my_errno), 2);
	else
		ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

t_scene	*read_scene(void *mlx_ptr, char *file_name)
{
	t_scene	*ret_scene;
	int		fd;
	int		sizex;
	int		sizey;

	if (is_invalid_filename(file_name))
		error_messege("Invalie scena file name", 0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_messege("", errno);
	ret_scene = read_scene_file(fd);
	close(fd);
	if (!ret_scene)
		error_messege("Invalid scena file syntax", 0);
	mlx_get_screen_size(mlx_ptr, &sizex, &sizey);
	if (ret_scene->convas.width > sizex)
		ret_scene->convas.width = sizex;
	if (ret_scene->convas.hight > sizey)
		ret_scene->convas.hight = sizey;
	return (ret_scene);
}

void	save_image(t_image *image, t_convas convas, char *scene_name)
{
	char	*picture_name;
	int		fd;

	picture_name = give_save_image_file_name(scene_name);
	if (!picture_name)
		error_messege("", 0);
	fd = open(picture_name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	free(picture_name);
	if (fd < 0)
		error_messege("", errno);
	if (save_image_to_fd(fd, image, convas))
		error_messege("", 0);
	close(fd);
}
