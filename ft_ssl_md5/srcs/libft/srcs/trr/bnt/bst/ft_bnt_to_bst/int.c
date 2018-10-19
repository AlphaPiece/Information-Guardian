/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:48:16 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:32:31 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bnt_to_bst.h"

static int	int_arr[MAXNODE];
static int	len = 0;

void		push_int_arr(void *data)
{
	if (len > MAXNODE)
	{
		ft_printf("error: too many nodes\n");
		return ;
	}
	int_arr[len++] = *((int *)data);
}

void		*pop_int_arr(void *data)
{
	static int	index = 0;

	if (index == len)
	{
		ft_printf("error: array is empty\n");
		return (NULL);
	}
	if (!data)
		return (NULL);
	return ((void *)(&int_arr[index++]));
}

int			cmp_int(int i, int j)
{
	if (int_arr[i] > int_arr[j])
		return (1);
	else if (int_arr[i] < int_arr[j])
		return (-1);
	return (0);
}

void		swap_int(int i, int j)
{
	ft_swap(sizeof(int_arr[0]), &int_arr[i], &int_arr[j]);	
}
