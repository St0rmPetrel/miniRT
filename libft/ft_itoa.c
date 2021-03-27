/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:46:37 by serma             #+#    #+#             */
/*   Updated: 2020/11/04 15:28:14 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_of_digit(int n)
{
	size_t	ret;

	ret = 0;
	if (n <= 0)
		ret++;
	while (n != 0)
	{
		ret++;
		n = n / 10;
	}
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	size_t	len_n;
	size_t	offset;

	len_n = len_of_digit(n);
	offset = 0;
	ret = (char *)ft_calloc((len_n + 1), sizeof(char));
	if (!ret)
		return (0);
	if (n < 0)
	{
		offset = 1;
		ret[0] = '-';
	}
	while (len_n > offset)
	{
		if (offset)
			ret[len_n - 1] = '0' - (n % 10);
		else
			ret[len_n - 1] = '0' + (n % 10);
		n = n / 10;
		len_n--;
	}
	return (ret);
}
