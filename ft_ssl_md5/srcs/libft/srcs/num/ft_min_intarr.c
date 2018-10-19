/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_intarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 14:47:26 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 14:49:36 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min_intarr(int arr[], size_t len)
{
	int		min;
	size_t	i;
	
	if (len == 0 || !arr)
		return (0);
	min = arr[0];
	i = 0;
	while (++i < len)
		if (min > arr[i])
			min = arr[i];
	return (min);
}
