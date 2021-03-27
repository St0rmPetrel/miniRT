/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:31:17 by telman            #+#    #+#             */
/*   Updated: 2021/01/25 12:44:17 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save_image.h"
#include "save_image_functions.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int		save_image_to_fd(int fd, t_image *image, t_convas convas)
{
	if (write_file_header(fd, convas.width, convas.hight))
		return (1);
	if (write_info_header(fd, convas.width, convas.hight))
		return (1);
	write_image(fd, image, convas.width, convas.hight);
	return (0);
}

int		write_file_header(int fd, int width, int height)
{
	unsigned char	*file_header;
	int				file_size;
	int				stride;
	int				padding_size;

	padding_size = (4 - (width * BYTES_PER_PIXEL) % 4) % 4;
	stride = width * BYTES_PER_PIXEL + padding_size;
	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);
	file_header = ft_calloc(FILE_HEADER_SIZE, 1);
	if (!file_header)
		return (1);
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	ft_memcpy((void *)(file_header + 2), (void *)(&file_size), 4);
	file_header[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	write(fd, file_header, FILE_HEADER_SIZE);
	free(file_header);
	return (0);
}

int		write_info_header(int fd, int width, int height)
{
	unsigned char *info_header;

	info_header = ft_calloc(INFO_HEADER_SIZE, 1);
	if (!info_header)
		return (1);
	info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	ft_memcpy((void *)(info_header + 4), (void *)(&width), 4);
	ft_memcpy((void *)(info_header + 8), (void *)(&height), 4);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	write(fd, info_header, INFO_HEADER_SIZE);
	free(info_header);
	return (0);
}

void	write_image(int fd, t_image *image, int width, int height)
{
	int		x;
	int		y;
	int		padding_size;
	int		color;
	char	padding[3];

	ft_bzero((void *)padding, 3);
	padding_size = (4 - (width * BYTES_PER_PIXEL) % 4) % 4;
	y = height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x <= (width - 1))
		{
			color = image_pixel_color(image, x, y);
			write(fd, &(color), 3);
			x++;
		}
		if (padding_size)
			write(fd, padding, padding_size);
		y--;
	}
}
