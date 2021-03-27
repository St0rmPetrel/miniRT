/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:51:46 by serma             #+#    #+#             */
/*   Updated: 2020/11/04 15:54:57 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_lst;

	if ((!lst) || (!del))
		return ;
	while (*lst)
	{
		current_lst = *lst;
		(*lst) = (*lst)->next;
		ft_lstdelone(current_lst, del);
	}
	*lst = 0;
}
