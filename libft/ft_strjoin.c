/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:17:47 by serma             #+#    #+#             */
/*   Updated: 2020/11/04 15:26:11 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_of_ret;
	size_t	len_of_s1;
	size_t	len_of_s2;
	char	*ret_s;

	if ((s1 == 0) || (s2 == 0))
		return (0);
	len_of_s1 = ft_strlen(s1);
	len_of_s2 = ft_strlen(s2);
	len_of_ret = len_of_s1 + len_of_s2;
	ret_s = ft_calloc((len_of_ret + 1), sizeof(*ret_s));
	if (ret_s)
	{
		ft_memcpy(ret_s, s1, len_of_s1);
		ft_memcpy((ret_s + len_of_s1), s2, len_of_s2);
	}
	return (ret_s);
}
