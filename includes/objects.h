/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:10:57 by serma             #+#    #+#             */
/*   Updated: 2021/01/30 13:51:14 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# define IS_PLANE 1
# define IS_SPHERE 2
# define IS_SQUARE 3
# define IS_TRIANGLE 4
# define IS_CYLINDER 5

# include "colors.h"
# include "vectormath.h"
# include "ray.h"

# define NO_SPECULAR -1

typedef struct	s_material
{
	t_color	color;
	double	reflection;
	double	refraction;
	int		specular;
}				t_material;

typedef struct	s_object
{
	t_material	material;
	int			type;
	void		*data;
}				t_object;

typedef struct	s_sphere
{
	t_point	center;
	double	diameter;
	double	r_square;
}				t_sphere;
double			ray_sphere_intersection(t_ray ray, t_sphere sphere);
t_vector		point_sphere_normal(t_point	intersec_point, t_sphere sphere);

typedef struct	s_plane
{
	t_vector	normal;
	t_point		point;
}				t_plane;
double			ray_plane_intersection(t_ray ray, t_plane plane);
t_vector		point_plane_normal(t_plane plane);

typedef struct	s_square
{
	t_vector	normal;
	t_point		center;
	double		size;
}				t_square;
double			ray_square_intersection(t_ray ray, t_square square);
t_vector		point_square_normal(t_square square);

typedef struct	s_triangle
{
	t_point		v0;
	t_point		v1;
	t_point		v2;
	t_vector	edge_1;
	t_vector	edge_2;
	t_vector	normal;
}				t_triangle;
double			ray_triangle_intersection(t_ray ray, t_triangle trianle);
t_vector		point_triangle_normal(t_triangle trianle);

typedef struct	s_cylinder
{
	t_point		center;
	t_vector	axis;
	double		diametr;
	double		height;
}				t_cylinder;
double			ray_cylinder_intersection(t_ray ray, t_cylinder cylinder);
t_vector		point_cylinder_normal(t_point intersec_point,
		t_cylinder cylinder);

#endif
