/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:56:41 by serma             #+#    #+#             */
/*   Updated: 2021/02/04 19:34:22 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectormath.h"
#include <math.h>

t_square_root	square_solve(double a, double b, double c)
{
	double			diskr;
	t_square_root	ret;

	diskr = pow(b, 2) - 4 * a * c;
	if (diskr < 0)
	{
		ret.root.x = 0;
		ret.root.y = 0;
		ret.exist = 0;
		return (ret);
	}
	ret.root.x = (-b + sqrt(diskr)) / (2 * a);
	ret.root.y = (-b - sqrt(diskr)) / (2 * a);
	ret.exist = 1;
	return (ret);
}
