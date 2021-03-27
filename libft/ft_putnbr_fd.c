/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:45:07 by serma             #+#    #+#             */
/*   Updated: 2020/11/01 19:08:28 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	current_num;
	int		mod_n;

	current_num = '0';
	mod_n = n % 10;
	if (mod_n < 0)
		current_num -= mod_n;
	else
		current_num += mod_n;
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	else if (mod_n < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd(current_num, fd);
}
