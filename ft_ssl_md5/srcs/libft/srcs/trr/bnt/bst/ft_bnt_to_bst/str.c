/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:52:39 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:32:41 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bnt_to_bst.h"

static char	*str_arr[MAXNODE];
static int	len = 0;

void		push_str_arr(void *data)
{
	if (len > MAXNODE)
	{
		ft_printf("error: too many nodes\n");
		return ;
	}
	str_arr[len++] = (char *)data;
}

void		*pop_str_arr(void *data)
{
	static int	index = 0;

	if (index == len)
	{
		ft_printf("error: array is empty\n");
		return (NULL);
	}
	if (!data)
		return (NULL);
	return ((void *)(str_arr[index++]));
}

int			cmp_str(int i, int j)
{
	return (ft_strcmp(str_arr[i], str_arr[j]));
}

void		swap_str(int i, int j)
{
	char	*tmp;

	tmp = str_arr[i];
	str_arr[i] = str_arr[j];
	str_arr[j] = tmp;
}
