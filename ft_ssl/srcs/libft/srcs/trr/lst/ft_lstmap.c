/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:47:14 by zwang             #+#    #+#             */
/*   Updated: 2018/07/16 10:35:44 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*node;
	t_list	*tmp;

	if (!(tmp = f(lst)))
		return (NULL);
	node = ft_lstnew(tmp->content, tmp->content_size);
	ptr = node;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp = f(lst)))
			return (NULL);
		node->next = ft_lstnew(tmp->content, tmp->content_size);
		node = node->next;
	}
	return (ptr);
}
