/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 19:47:24 by zwang             #+#    #+#             */
/*   Updated: 2018/10/09 20:16:12 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap_arr_mbr(char *arr[], int i, int j)
{
	char	*tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void		ft_strarrsort(char *arr[], int len,
							int (*cmp)(const char *, const char *))
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
			while (j >= 0 && cmp(arr[j], arr[j + gap]) > 0)
			{
				swap_arr_mbr(arr, j, j + gap);
				j -= gap;
			}
			i++;
		}
		gap /= 2;
	}
}
