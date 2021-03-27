/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:11:12 by serma             #+#    #+#             */
/*   Updated: 2020/11/05 17:59:01 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;
	int		ret;

	counter = 0;
	ret = 0;
	if (n == 0)
		return (0);
	while ((s1[counter] != '\0') && (s2[counter] != '\0') && (counter < n))
	{
		ret = (unsigned char)s1[counter] - (unsigned char)s2[counter];
		if (ret != 0)
			return (ret);
		counter++;
	}
	if (counter < n)
		ret = (unsigned char)s1[counter] - (unsigned char)s2[counter];
	return (ret);
}
