/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:09:26 by serma             #+#    #+#             */
/*   Updated: 2021/01/14 20:45:08 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_history_list	*add_new_file_in_history(int fd, t_history_list **history)
{
	t_history_list	*current_file;

	current_file = (t_history_list *)malloc(sizeof(t_history_list));
	if (!current_file)
		return (NULL);
	current_file->fd = fd;
	current_file->next = 0;
	current_file->save_string = (char *)malloc(1 * sizeof(char));
	if (!(current_file->save_string))
	{
		free(current_file);
		return (NULL);
	}
	*(current_file->save_string) = '\0';
	if (*history)
		current_file->next = *history;
	*history = current_file;
	return (current_file);
}

char			*ft_strcdup(const char *s1, int c)
{
	size_t	len_of_s1;
	char	*c_place_in_s1;
	char	*ret_s;

	c_place_in_s1 = ft_strchr(s1, c);
	if (!c_place_in_s1)
		return (NULL);
	len_of_s1 = (size_t)(c_place_in_s1 - s1);
	ret_s = malloc((len_of_s1 + 1) * sizeof(char));
	if (!ret_s)
		return (NULL);
	ret_s[len_of_s1] = '\0';
	if (ret_s)
		ret_s = ft_memcpy(ret_s, s1, len_of_s1);
	return (ret_s);
}
