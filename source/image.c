/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:12:13 by serma             #+#    #+#             */
/*   Updated: 2021/01/23 15:51:22 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "libft.h"
#include "mlx.h"

void	image_pixel_put(t_image *data, int color, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		image_pixel_color(t_image *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

t_image	*create_new_image(void *mlx_ptr, t_convas convas)
{
	t_image	*ret_img;

	ret_img = ft_calloc(1, sizeof(t_image));
	if (!ret_img)
		return (NULL);
	ret_img->img = mlx_new_image(mlx_ptr, convas.width, convas.hight);
	if (!ret_img)
	{
		free(ret_img);
		return (NULL);
	}
	ret_img->addr = mlx_get_data_addr(ret_img->img, &(ret_img->bits_per_pixel),
			&(ret_img->line_length), &(ret_img->endian));
	return (ret_img);
}
