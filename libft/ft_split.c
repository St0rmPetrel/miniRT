/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:44:21 by serma             #+#    #+#             */
/*   Updated: 2020/11/05 19:42:06 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*move_to_begin_next_word(const char *s, char c)
{
	while ((*s != c) && (*s != '\0'))
		s++;
	while ((*s == c) && (*s != '\0'))
		s++;
	return ((char *)s);
}

static size_t	count_words(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s != '\0')
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		if ((*s != c) && (*s != '\0'))
			ret++;
		while ((*s != c) && (*s != '\0'))
			s++;
	}
	return (ret);
}

static size_t	len_next_word(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while ((*s != c) && (*s != '\0'))
	{
		ret++;
		s++;
	}
	return (ret);
}

static void		ft_cleanall(char **strings, size_t curren_string_num)
{
	size_t	counter;

	counter = 0;
	if (curren_string_num > 0)
		counter = curren_string_num - 1;
	while (counter != 0)
	{
		free(strings[counter]);
		counter--;
	}
	free(strings[counter]);
	free(strings);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count_of_words;
	size_t	counter;
	size_t	len_word;

	if (s == 0)
		return (0);
	count_of_words = count_words(s, c);
	ret = ft_calloc((count_of_words + 1), sizeof(*ret));
	if (!ret)
		return (0);
	while ((*s == c) && (*s != '\0'))
		s++;
	counter = 0;
	while (counter < count_of_words)
	{
		len_word = len_next_word(s, c);
		ret[counter] = ft_calloc((len_word + 1), sizeof(**ret));
		if (!ret[counter])
			ft_cleanall(ret, counter);
		ft_memcpy(ret[counter], s, len_word);
		s = move_to_begin_next_word(s, c);
		counter++;
	}
	return (ret);
}
