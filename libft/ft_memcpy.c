/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:16:18 by serma             #+#    #+#             */
/*   Updated: 2020/11/05 12:55:45 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	counter;

	counter = 0;
	if (!(dest || src))
		return (0);
	while (counter < n)
	{
		*(char *)(dest + counter) = *(char *)(src + counter);
		counter++;
	}
	return (dest);
}
