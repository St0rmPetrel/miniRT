/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:00:52 by serma             #+#    #+#             */
/*   Updated: 2021/01/23 14:53:20 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "convas.h"

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

void			image_pixel_put(t_image *data, int color, int x, int y);
int				image_pixel_color(t_image *data, int x, int y);
t_image			*create_new_image(void *mlx_ptr, t_convas convas);

#endif
