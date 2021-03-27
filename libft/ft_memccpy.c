/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:56:04 by serma             #+#    #+#             */
/*   Updated: 2020/11/03 18:38:49 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		*(char *)(dest + counter) = *(char *)(src + counter);
		if (*(char *)(dest + counter) == (char)c)
			return (dest + counter + 1);
		counter++;
	}
	return (NULL);
}
