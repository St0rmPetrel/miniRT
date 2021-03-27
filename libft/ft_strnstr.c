/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:08:02 by serma             #+#    #+#             */
/*   Updated: 2020/11/05 17:13:50 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;
	size_t	offset;

	counter = 0;
	offset = 0;
	if (((*haystack == '\0') && (*needle == '\0')) || \
			((len == 0) && (*needle == '\0')))
		return ((char *)haystack);
	while ((counter < len) && (haystack[counter] != '\0'))
	{
		offset = 0;
		while ((haystack[counter + offset] == needle[offset]) && \
				(haystack[counter + offset] != '\0') && \
				(needle[offset] != '\0') && ((counter + offset) < len))
			offset++;
		if (needle[offset] == '\0')
			return ((char *)haystack + counter);
		counter++;
	}
	return (NULL);
}
