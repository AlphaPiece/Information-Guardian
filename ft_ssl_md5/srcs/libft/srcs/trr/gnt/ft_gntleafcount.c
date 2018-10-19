/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gntleafcount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:52:14 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:27:17 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_gntleafcount(t_tree *gnt)
{
	int		*leaf_arr;
	int		i;
	int		sum;
	
	if (!gnt->children)
		return (1);
	leaf_arr = (int *)malloc(sizeof(int) * gnt->child_nbr);
	i = -1;
	while (++i < gnt->child_nbr)
		leaf_arr[i] = ft_gntleafcount(gnt->children[i]);
	sum = ft_sum_intarr(leaf_arr, gnt->child_nbr);
	free(leaf_arr);
	return (sum);
}
