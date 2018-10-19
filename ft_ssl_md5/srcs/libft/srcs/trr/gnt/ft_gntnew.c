/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gntnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:34:46 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:25:52 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_gntnew(void *data)
{
	t_tree		*node;

	if (!(node = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	node->data = data;
	node->parent = NULL;
	node->children = NULL;
	node->child_nbr = 0;
	return (node);
}
