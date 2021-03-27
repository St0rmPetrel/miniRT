/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:08:49 by serma             #+#    #+#             */
/*   Updated: 2020/11/03 19:48:10 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;
	int		result;

	counter = 0;
	result = 0;
	while (counter < n)
	{
		result = (int)(*(unsigned char *)(s1 + counter) - \
				*(unsigned char *)(s2 + counter));
		if (result != 0)
			return (result);
		counter++;
	}
	return (0);
}
