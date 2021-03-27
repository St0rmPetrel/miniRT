/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:48:18 by serma             #+#    #+#             */
/*   Updated: 2021/02/01 14:13:41 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_DATA_H
# define DRAW_DATA_H

# include "image.h"
# include "camera.h"
# include "scene.h"
# define T_NUM 8

typedef struct	s_draw_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*image;
	t_scene		*scene;
	int			current_camera;
	int			is_caps;
}				t_draw_data;

typedef struct	s_thread_draw_data
{
	t_camera	*camera;
	t_image		*image;
	t_scene		*scene;
	int			index_t;
}				t_thread_draw_data;
void			*thread_draw(void *data);

int				draw_scene_in_image(t_image *image, t_scene *scene, \
														int camera_num);
#endif
