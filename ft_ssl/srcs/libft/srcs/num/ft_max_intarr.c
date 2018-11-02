/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_intarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:42:59 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 14:46:55 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max_intarr(int arr[], size_t len)
{
	int		max;
	size_t	i;

	if (len == 0 || !arr)
		return (0);
	max = arr[0];
	i = 0;
	while (++i < len)
		if (max < arr[i])
			max = arr[i];
	return (max);
}
