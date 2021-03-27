/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:06:54 by serma             #+#    #+#             */
/*   Updated: 2021/01/31 16:15:53 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "libft.h"
# include "convas.h"
# include "image.h"

# define IS_CAMERA 1
# define IS_OBJECT 2
# define IS_LIGHT 3

typedef struct	s_scene
{
	t_convas	convas;
	t_list		*cameras;
	t_list		*objects;
	t_list		*lights;
}				t_scene;

int				add_in_scene(void *object, t_scene *scene, int type);
void			free_scene(t_scene *scene);

#endif
