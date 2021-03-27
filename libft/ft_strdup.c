/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:17:43 by serma             #+#    #+#             */
/*   Updated: 2020/11/04 14:53:21 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_of_s1;
	char	*ret_s;

	len_of_s1 = ft_strlen(s1);
	ret_s = ft_calloc((len_of_s1 + 1), sizeof(*s1));
	if (ret_s)
		ret_s = ft_memcpy(ret_s, s1, len_of_s1);
	return (ret_s);
}
