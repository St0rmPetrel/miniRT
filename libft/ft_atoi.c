/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:35:01 by serma             #+#    #+#             */
/*   Updated: 2020/11/06 18:14:19 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n') \
			|| (c == '\v') || (c == '\f') || (c == '\r'))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int	ret;
	int	flag_minus;

	ret = 0;
	flag_minus = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		flag_minus = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		ret = 10 * ret + (*str) - '0';
		str++;
	}
	if (flag_minus)
		return (-ret);
	return (ret);
}
