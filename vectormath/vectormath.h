/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormath.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:36:16 by serma             #+#    #+#             */
/*   Updated: 2021/02/01 16:51:21 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORMATH_H
# define VECTORMATH_H

# define PI 3.14159265358979311599796346854

typedef struct		s_vector
{
	double	x;
	double	y;
	double	z;
}					t_vector;

typedef t_vector	t_point;

t_vector			vec_set(double x, double y, double z);
t_vector			vec_add(t_vector v1, t_vector v2);
t_vector			vec_sub(t_vector v1, t_vector v2);
double				vec_dot(t_vector v1, t_vector v2);
t_vector			vec_cross(t_vector v1, t_vector v2);
t_vector			vec_mul(t_vector v1, double t);
t_vector			vec_div(t_vector v1, double t);
double				vec_length(t_vector v1);
double				vec_length2(t_vector v1);
t_vector			vec_normalize(t_vector v1);
int					is_null_vec(t_vector v);

typedef struct		s_matrix
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
}					t_matrix;

t_matrix			give_rotate_matrix(t_vector axis, double teta);
t_vector			matrix_mul_vec(t_matrix matrix, t_vector v);
t_vector			vec_rotate(t_vector v, t_vector axis, double teta);

typedef struct		s_vector2
{
	double	x;
	double	y;
}					t_vector2;

t_vector2			vec2_set(double x, double y);
t_vector2			vec2_add(t_vector2 v1, t_vector2 v2);
t_vector2			vec2_sub(t_vector2 v1, t_vector2 v2);
double				vec2_dot(t_vector2 v1, t_vector2 v2);
t_vector2			vec2_mul(t_vector2 v1, double t);
t_vector2			vec2_div(t_vector2 v1, double t);
double				vec2_length(t_vector2 v1);
double				vec2_length2(t_vector2 v1);
t_vector2			vec2_normalize(t_vector2 v1);

typedef struct		s_square_root
{
	t_vector2	root;
	int			exist;
}					t_square_root;
t_square_root		square_solve(double a, double b, double c);

#endif
