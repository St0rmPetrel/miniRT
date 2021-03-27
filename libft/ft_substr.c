/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:48:22 by serma             #+#    #+#             */
/*   Updated: 2020/11/04 16:37:58 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_of_substr;
	char	*ret_s;

	if (s == 0)
		return (NULL);
	len_of_substr = 0;
	if (ft_strlen(s) > start)
		len_of_substr = ft_strlen(s + start);
	if (len_of_substr > len)
		len_of_substr = len;
	ret_s = ft_calloc((len_of_substr + 1), sizeof(*s));
	if (ret_s)
		ret_s = ft_memcpy(ret_s, (s + start), len_of_substr);
	return (ret_s);
}
