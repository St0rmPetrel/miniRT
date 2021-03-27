/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:21:04 by serma             #+#    #+#             */
/*   Updated: 2021/02/02 16:26:13 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_handler.h"
#include <stdlib.h>

int			len_of_array(void **arr)
{
	int	ret;

	ret = 0;
	while (*arr)
	{
		ret++;
		arr++;
	}
	return (ret);
}

void		free_array(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
