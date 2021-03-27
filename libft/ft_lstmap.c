/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:19:12 by serma             #+#    #+#             */
/*   Updated: 2020/11/03 15:18:13 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new_element;
	void	*new_content;

	ret = 0;
	new_content = 0;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_element = 0;
		if (new_content)
			new_element = ft_lstnew(new_content);
		if (new_element)
			ft_lstadd_back(&ret, new_element);
		else
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (ret);
}
