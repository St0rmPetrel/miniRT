/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:48:03 by serma             #+#    #+#             */
/*   Updated: 2021/02/03 12:28:56 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "parse_line.h"
#include "get_next_line.h"

static t_scene	*file_check(t_scene *scene, int res_f)
{
	if (!res_f)
	{
		free_scene(scene);
		return (NULL);
	}
	return (scene);
}

t_scene	*read_scene_file(int fd)
{
	char	*line;
	t_scene	*ret_scene;
	int		ret_gnl;
	int		res_f;

	ret_scene = ft_calloc(1, sizeof(t_scene));
	res_f = 0;
	if (!ret_scene)
		return (NULL);
	while ((ret_gnl = get_next_line(fd, &line)))
	{
		if ((ret_gnl == -1) || (parse_line(line, ret_scene)))
		{
			free(line);
			free_scene(ret_scene);
			return (NULL);
		}
		if (*line == 'R')
			res_f = 1;
		free(line);
	}
	free(line);
	return (file_check(ret_scene, res_f));
}
