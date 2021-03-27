/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:04:09 by serma             #+#    #+#             */
/*   Updated: 2021/01/14 20:49:07 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			delete_file_from_history(int fd, t_history_list **history)
{
	t_history_list		*current_element;
	t_history_list		*temp;

	current_element = *history;
	if (!current_element)
		return ;
	if (current_element->fd == fd)
	{
		free(current_element->save_string);
		*history = current_element->next;
		free(current_element);
		return ;
	}
	while (current_element->next)
	{
		if (current_element->fd == fd)
		{
			free((current_element->next)->save_string);
			temp = current_element->next;
			current_element->next = (current_element->next)->next;
			free(temp);
			return ;
		}
		current_element = current_element->next;
	}
}

t_history_list	*search_in_history(int fd, t_history_list **history, char **l)
{
	t_history_list	*current_file;

	if ((fd < 0) || (l == 0))
		return (0);
	current_file = *history;
	while (current_file)
	{
		if (current_file->fd == fd)
			return (current_file);
		current_file = current_file->next;
	}
	current_file = add_new_file_in_history(fd, history);
	return (current_file);
}

int				read_to_save_string(int fd, t_history_list *current_file, \
		t_history_list **history)
{
	int		ret;
	char	*temp;
	char	*buf;

	if (BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		delete_file_from_history(fd, history);
	if (!buf)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == -1)
		delete_file_from_history(fd, history);
	if (ret == -1)
		return (-1);
	buf[ret] = '\0';
	temp = ft_strjoin(current_file->save_string, buf);
	(!temp) ? (delete_file_from_history(fd, history)) : (1);
	if (!temp)
		return (-1);
	free(buf);
	free(current_file->save_string);
	current_file->save_string = temp;
	return (ret);
}

int				put_in_line(char **line, t_history_list *current_file, \
		t_history_list **history)
{
	char	*temp;

	*line = ft_strcdup(current_file->save_string, '\n');
	if (!(*line))
	{
		delete_file_from_history(current_file->fd, history);
		return (0);
	}
	temp = ft_strcdup((ft_strchr(current_file->save_string, '\n') + 1), '\0');
	if (!temp)
	{
		delete_file_from_history(current_file->fd, history);
		return (0);
	}
	free(current_file->save_string);
	current_file->save_string = temp;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_history_list		*history;
	t_history_list				*current_file;
	int							how_many_readed;

	current_file = search_in_history(fd, &history, line);
	if (!current_file)
		return (-1);
	how_many_readed = 0;
	while (!(ft_strchr(current_file->save_string, '\n')))
	{
		how_many_readed = read_to_save_string(fd, current_file, &history);
		if (!how_many_readed)
		{
			*line = ft_strcdup(current_file->save_string, '\0');
			delete_file_from_history(fd, &history);
			if (!(line))
				return (-1);
			return (0);
		}
		else if (how_many_readed == (-1))
			return (-1);
	}
	if (!put_in_line(line, current_file, &history))
		return (-1);
	return (1);
}
