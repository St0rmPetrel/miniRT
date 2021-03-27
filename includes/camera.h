/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:22:13 by serma             #+#    #+#             */
/*   Updated: 2021/02/01 17:09:25 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vectormath.h"
# include "convas.h"

typedef struct		s_coordinate_system
{
	double		distance;
	t_matrix	basis;
}					t_coordinate_system;

typedef struct		s_camera
{
	t_point				origin;
	t_vector			view;
	double				fov;
	t_coordinate_system	crd;
}					t_camera;

t_coordinate_system	give_camera_coordinate_system(t_convas convas,
		t_camera camera);

#endif
