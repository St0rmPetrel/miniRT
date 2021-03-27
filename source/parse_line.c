/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:49:27 by serma             #+#    #+#             */
/*   Updated: 2021/02/02 19:45:37 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_line.h"
#include "libft.h"
#include "set_add.h"

void	free_words(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int		ft_isupper(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (1);
	return (0);
}

int		set(char **words, t_scene *scene)
{
	char		*comand;
	int			is_error;
	static int	is_r_set;
	static int	is_a_set;

	is_error = 0;
	comand = words[0];
	if ((ft_strncmp(comand, "R", 2) == 0) && (!is_r_set))
	{
		is_r_set = 1;
		if (set_resolution(words, scene))
			is_error = 1;
	}
	else if ((ft_strncmp(comand, "A", 2) == 0) && (!is_a_set))
	{
		is_a_set = 1;
		if (set_ambient_lightning(words, scene))
			is_error = 1;
	}
	else
		is_error = 1;
	if (is_error)
		return (1);
	return (0);
}

int		add(char **words, t_scene *scene)
{
	char	*comand;
	int		is_error;

	is_error = 0;
	comand = words[0];
	if (ft_strncmp(comand, "c", 2) == 0)
	{
		if (add_camera(words, scene))
			is_error = 1;
	}
	else if (ft_strncmp(comand, "l", 1) == 0)
	{
		if (add_light(words, scene))
			is_error = 1;
	}
	else
	{
		if (add_object(words, scene))
			is_error = 1;
	}
	if (is_error)
		return (1);
	return (0);
}

int		parse_line(char *line, t_scene *scene)
{
	char	**words;
	int		is_error;

	is_error = 0;
	if ((!line[0]) || (line[0] == '#'))
		return (0);
	words = ft_split(line, ' ');
	if (!words)
		return (1);
	if (ft_isupper(words[0][0]))
	{
		if (set(words, scene))
			is_error = 1;
	}
	else if (ft_isalpha(words[0][0]))
	{
		if (add(words, scene))
			is_error = 1;
	}
	else
		is_error = 1;
	free_words(words);
	if (is_error)
		return (1);
	return (0);
}
