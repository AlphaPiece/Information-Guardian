/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:48:16 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:32:36 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bnt_to_bst.h"

static long	long_arr[MAXNODE];
static int	len = 0;

void		push_long_arr(void *data)
{
	if (len > MAXNODE)
	{
		ft_printf("error: too many nodes\n");
		return ;
	}
	long_arr[len++] = *((long *)data);
}

void		*pop_long_arr(void *data)
{
	static int	index = 0;

	if (index == len)
	{
		ft_printf("error: array is empty\n");
		return (NULL);
	}
	if (!data)
		return (NULL);
	return ((void *)(&long_arr[index++]));
}

int			cmp_long(int i, int j)
{
	if (long_arr[i] > long_arr[j])
		return (1);
	else if (long_arr[i] < long_arr[j])
		return (-1);
	return (0);
}

void		swap_long(int i, int j)
{
	ft_swap(sizeof(long_arr[0]), &long_arr[i], &long_arr[j]);	
}
