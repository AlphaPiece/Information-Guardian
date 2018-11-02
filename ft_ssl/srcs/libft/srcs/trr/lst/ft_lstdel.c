/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:10:04 by zwang             #+#    #+#             */
/*   Updated: 2018/07/13 14:37:08 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next_node;

	if (alst)
	{
		node = *alst;
		while (node)
		{
			next_node = node->next;
			del(node->content, node->content_size);
			free(node);
			node = next_node;
		}
		*alst = NULL;
	}
}
