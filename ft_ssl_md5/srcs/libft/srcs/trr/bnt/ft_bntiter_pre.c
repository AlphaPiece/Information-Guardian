/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bntiter_pre.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:07:25 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 13:26:28 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** pre-order traversal; parse data of each node to f
*/

void	ft_bntiter_pre(t_btree *node, void (*f)(void *))
{
	if (node)
	{
		f(node->data);
		ft_bntiter_pre(node->left, f);
		ft_bntiter_pre(node->right, f);
	}
}
