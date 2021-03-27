/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:41:22 by serma             #+#    #+#             */
/*   Updated: 2020/11/05 13:01:35 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	size_t	counter;

	counter = n;
	if (!(dest || src))
		return (0);
	if (n >= 1)
		counter--;
	else
		return (dest);
	while (counter != 0)
	{
		*(char *)(dest + counter) = *(char *)(src + counter);
		counter--;
	}
	*(char *)(dest + counter) = *(char *)(src + counter);
	return (dest);
}

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!(dest || src))
		return (NULL);
	if (src >= dest)
		ft_memcpy(dest, src, n);
	else
		ft_memrcpy(dest, src, n);
	return (dest);
}
