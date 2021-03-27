/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:34:05 by serma             #+#    #+#             */
/*   Updated: 2021/01/23 21:23:23 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_handler.h"
#include "file_name_handler.h"
#include "libft.h"

int		is_invalid_filename(char *file_name)
{
	char	**file_name_split;
	int		len;
	int		ret;

	ret = 1;
	file_name_split = ft_split(file_name, '.');
	if (!file_name_split)
		return (1);
	len = len_of_array((void **)file_name_split);
	if (!ft_strncmp(file_name_split[len - 1], "rt", 3))
		ret = 0;
	if (len < 2)
		ret = 1;
	free_array((void **)file_name_split);
	return (ret);
}

char	*give_save_image_file_name(char *file_name)
{
	char	**file_name_split;
	int		len;
	char	*ret;

	file_name_split = ft_split(file_name, '.');
	if (!file_name_split)
		return (NULL);
	len = len_of_array((void **)file_name_split);
	if (len < 2)
	{
		free_array((void **)file_name_split);
		return (NULL);
	}
	ret = ft_strjoin(file_name_split[len - 2], ".bmp");
	free_array((void **)file_name_split);
	return (ret);
}
