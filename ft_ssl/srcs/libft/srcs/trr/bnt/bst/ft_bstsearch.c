/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:12:07 by zwang             #+#    #+#             */
/*   Updated: 2018/10/06 20:27:17 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bstsearch(t_btree *bst, void *data_ref, int (*cmp)(void *, void *))
{
	int	flag;

	if (!bst)
		return (NULL);
	else if ((flag = cmp(data_ref, bst->data)) == 0)
		return (bst->data);
	else if (flag < 0)
		return (ft_bstsearch(bst->left, data_ref, cmp));
	return (ft_bstsearch(bst->right, data_ref, cmp));
}
