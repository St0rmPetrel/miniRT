/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:59:29 by serma             #+#    #+#             */
/*   Updated: 2020/11/05 19:31:26 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len_s1;
	size_t	counter;

	if (!(s1 && set))
		return (0);
	while ((ft_isinset(*s1, set)) && (*s1 != '\0'))
		s1++;
	len_s1 = ft_strlen(s1);
	counter = 0;
	if (len_s1)
		counter = len_s1 - 1;
	else
	{
		ret = (char *)ft_calloc(1, sizeof(char));
		return (ret);
	}
	while ((ft_isinset(s1[counter], set)) && (counter > 0))
		counter--;
	ret = (char *)ft_calloc((counter + 2), sizeof(char));
	if (ret)
		ft_memcpy(ret, s1, (counter + 1));
	return (ret);
}
