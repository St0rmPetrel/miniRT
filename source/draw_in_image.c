/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_in_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:05:20 by serma             #+#    #+#             */
/*   Updated: 2021/02/01 14:12:32 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_data.h"
#include "give.h"
#include <pthread.h>

static void					*fill_data(t_image *image, t_scene *scene,
		t_camera *camera)
{
	t_thread_draw_data	*ret;

	ret = ft_calloc(1, sizeof(t_thread_draw_data));
	if (!ret)
		return (NULL);
	ret->scene = scene;
	ret->image = image;
	ret->camera = camera;
	ret->index_t = 0;
	return ((void *)ret);
	return (ret);
}

static t_thread_draw_data	**create_data(t_image *image,
		t_scene *scene, t_camera *camera)
{
	t_thread_draw_data	**ret;
	int					i;

	ret = ft_calloc(T_NUM, sizeof(t_thread_draw_data));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < T_NUM)
	{
		ret[i] = fill_data(image, scene, camera);
		(ret[i])->index_t = i + 1;
		if (!ret[i])
		{
			while (i > 0)
			{
				i--;
				free(ret[i]);
			}
			return (NULL);
		}
		i++;
	}
	return (ret);
}

int							draw_scene_in_image(t_image *image,
		t_scene *scene, int camera_num)
{
	t_camera			*camera;
	t_thread_draw_data	**data;
	pthread_t			thread_ids[T_NUM];
	int					i;

	camera = give_camera(*scene, camera_num);
	if (!camera)
		return (1);
	camera->crd = give_camera_coordinate_system(scene->convas, *camera);
	data = create_data(image, scene, camera);
	i = 0;
	while (i < T_NUM)
	{
		pthread_create(&(thread_ids[i]), NULL, thread_draw, data[i]);
		i++;
	}
	i = 0;
	while (i < T_NUM)
	{
		pthread_join(thread_ids[i], NULL);
		free(data[i]);
		i++;
	}
	free(data);
	return (0);
}

void						*thread_draw(void *data)
{
	int					hight;
	int					color;
	int					i;
	int					j;
	t_thread_draw_data	*data_t;

	data_t = ((t_thread_draw_data *)data);
	if (data_t->index_t != T_NUM)
		hight = data_t->index_t * ((data_t->scene->convas).hight / T_NUM);
	else
		hight = (data_t->scene->convas).hight;
	j = (data_t->index_t - 1) * ((data_t->scene->convas).hight / T_NUM);
	while (j < hight)
	{
		i = 0;
		while (i < (data_t->scene->convas).width)
		{
			color = give_pixel_color(i, j, data_t->camera, data_t->scene);
			image_pixel_put(data_t->image, color, i, j);
			i++;
		}
		j++;
	}
	pthread_exit(NULL);
}
