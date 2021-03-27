/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:14:12 by serma             #+#    #+#             */
/*   Updated: 2020/11/04 13:10:41 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	counter = 0;
	if (!(dst || src))
		return (0);
	while (((counter + 1) < dstsize) && (src[counter] != '\0'))
	{
		*(dst + counter) = *(src + counter);
		counter++;
	}
	if (dstsize >= 1)
	{
		*(dst + counter) = *(src + counter);
		*(dst + dstsize - 1) = '\0';
	}
	return (ft_strlen(src));
}
