/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:51:44 by serma             #+#    #+#             */
/*   Updated: 2021/01/18 16:22:28 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "del_functions.h"
#include "light.h"
#include "objects.h"
#include <stdlib.h>

void	del_object(void *object)
{
	free(((t_object *)object)->data);
	free(object);
}

void	del_light(void *light)
{
	free(((t_light *)light)->data);
	free(light);
}

void	del_camera(void *camera)
{
	free(camera);
}
