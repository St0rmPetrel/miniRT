/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:08:21 by serma             #+#    #+#             */
/*   Updated: 2020/11/06 15:23:13 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	dstsize_start;

	counter = 0;
	dstsize_start = ft_strlen(dst);
	if (dstsize > dstsize_start)
	{
		while (((counter + dstsize_start + 1) < dstsize) && (src[counter]))
		{
			dst[dstsize_start + counter] = src[counter];
			counter++;
		}
		dst[counter + dstsize_start] = '\0';
		return (ft_strlen(src) + dstsize_start);
	}
	return (ft_strlen(src) + dstsize);
}
