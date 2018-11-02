/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bnt_to_bst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:10:30 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:33:22 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bnt_to_bst.h"

static void	sort_arr(int len, int (*cmp)(int, int), void (*swap)(int, int))
{
	int	gap;
	int	i;
	int	j;

	gap = len / 2;
	while (gap > 0)
	{
		i = gap;
		while (i < len)
		{
			j = i - gap;
			while (j >= 0 && cmp(j, j + gap) > 0)
			{
				swap(j, j + gap);
				j -= gap;
			}
			i++;
		}
		gap /= 2;
	}
}

t_btree		*ft_bnt_to_bst(t_btree *bnt, int node_amt, char *data_type)
{
	if (ft_strcmp(data_type, "int") == 0)
	{
		ft_bntiter_in(bnt, push_int_arr);
		sort_arr(node_amt, cmp_int, swap_int);
		ft_bntalter_in(bnt, pop_int_arr);
	}
	else if (ft_strcmp(data_type, "long") == 0)
	{
		ft_bntiter_in(bnt, push_long_arr);
		sort_arr(node_amt, cmp_long, swap_long);
		ft_bntalter_in(bnt, pop_long_arr);
	}
	else if (ft_strcmp(data_type, "str") == 0)
	{
		ft_bntiter_in(bnt, push_str_arr);
		sort_arr(node_amt, cmp_str, swap_str);
		ft_bntalter_in(bnt, pop_str_arr);
	}
	else
	{
		ft_printf("error: unknown data type %s\n", data_type);
		return (NULL);
	}
	return (bnt);
}
