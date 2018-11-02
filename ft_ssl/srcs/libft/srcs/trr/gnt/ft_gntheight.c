/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gntheight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:26:48 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:27:33 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_gntheight(t_tree *gnt)
{
	int		*path_arr;
	int		i;
	int		max;

	if (!gnt->children)
		return (1);
	path_arr = (int *)malloc(sizeof(int) * gnt->child_nbr);
	i = -1;
	while (++i < gnt->child_nbr)
		path_arr[i] = ft_gntheight(gnt->children[i]);
	max = ft_max_intarr(path_arr, (size_t)gnt->child_nbr);
	free(path_arr);
	return (1 + max);
}
