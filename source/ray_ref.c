/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_ref.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:25:06 by serma             #+#    #+#             */
/*   Updated: 2021/01/20 23:16:05 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "intersection.h"
#include "vectormath.h"
#include <math.h>

t_ray	ray_reflect(t_ray ray, t_intersection hit)
{
	t_ray		ret_ray;
	t_vector	ray_dn;
	t_vector	ray_dt;

	ret_ray.origin = calculate(ray, hit.t);
	ret_ray.refl_deep = ray.refl_deep + 1;
	ret_ray.refr_deep = ray.refr_deep;
	ret_ray.t_max = ray.t_max;
	ray_dn = vec_mul(hit.normal, vec_dot(ray.direction, hit.normal));
	ray_dt = vec_sub(ray.direction, ray_dn);
	ret_ray.direction = vec_add(ray_dt, vec_mul(ray_dn, -1));
	return (ret_ray);
}

t_ray	ray_refract(t_ray ray, t_intersection hit)
{
	t_ray		ret_ray;
	t_vector	r[2];
	double		rd_dot_hn;
	double		size_of_r_sq;
	double		size_of_r_n1_sq;

	ret_ray = ray;
	ret_ray.refr_deep = ray.refr_deep + 1;
	rd_dot_hn = vec_dot(ray.direction, hit.normal);
	r[0] = vec_mul(hit.normal, rd_dot_hn);
	r[1] = vec_sub(ray.direction, r[0]);
	r[0] = vec_normalize(r[0]);
	if (rd_dot_hn >= 0)
		size_of_r_sq = pow(1 / hit.material.refraction, 2);
	else
		size_of_r_sq = pow(hit.material.refraction, 2);
	size_of_r_n1_sq = size_of_r_sq - vec_length2(r[1]);
	if (size_of_r_n1_sq < 0)
		return (ray_reflect(ret_ray, hit));
	r[0] = vec_mul(r[0], sqrt(size_of_r_n1_sq));
	ret_ray.origin = calculate(ray, hit.t);
	ret_ray.direction = vec_normalize(vec_add(r[0], r[1]));
	return (ret_ray);
}
