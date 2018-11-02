/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bntalter_pre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:17:38 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 13:26:05 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** pre-order traversal; parse data of each node to f and assign f value back
*/

void	ft_bntalter_pre(t_btree *node, void *(*f)(void *))
{
	if (node)
	{
		node->data = f(node->data);
		ft_bntalter_pre(node->left, f);
		ft_bntalter_pre(node->right, f);
	}
}
