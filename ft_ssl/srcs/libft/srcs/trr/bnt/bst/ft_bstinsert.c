/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:11:24 by zwang             #+#    #+#             */
/*   Updated: 2018/10/01 09:43:01 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_bstinsert(t_btree *bst, void *item, int (*cmp)(void *, void *))
{
	if (!bst)
		bst = ft_bntnew(item);
	else if (cmp(item, bst->data) < 0)
		bst->left = ft_bstinsert(bst->left, item, cmp);
	else
		bst->right = ft_bstinsert(bst->right, item, cmp);
	return (bst);
}
