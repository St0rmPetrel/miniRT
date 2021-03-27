/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:09:33 by serma             #+#    #+#             */
/*   Updated: 2020/11/04 15:31:37 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*ret;

	counter = 0;
	if ((s == 0) || (f == 0))
		return (0);
	ret = ft_strdup(s);
	while ((*s != '\0') && (ret))
	{
		ret[counter] = (*f)(counter, *s);
		counter++;
		s++;
	}
	return (ret);
}
