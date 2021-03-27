/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:20:18 by serma             #+#    #+#             */
/*   Updated: 2020/10/29 22:03:36 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	counter;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		if ((char)(c) == *(s + counter))
			return ((char *)s + counter);
		counter++;
	}
	if ((char)(c) == *(s + counter))
		return ((char *)s + counter);
	return (NULL);
}
