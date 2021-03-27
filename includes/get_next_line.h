/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 21:40:18 by serma             #+#    #+#             */
/*   Updated: 2021/01/14 20:49:29 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 128
# include "libft.h"

typedef struct	s_history_list
{
	char					*save_string;
	int						fd;
	struct s_history_list	*next;
}				t_history_list;

t_history_list	*add_new_file_in_history(int fd, t_history_list **history);

char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcdup(const char *s1, int c);

int				get_next_line(int fd, char **line);

#endif
