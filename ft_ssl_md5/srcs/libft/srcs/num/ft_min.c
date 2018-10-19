/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:35:06 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 09:40:16 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int total_num, ...)
{
	va_list	num_list;
	int		min;
	int		num;
	int		i;

	va_start(num_list, total_num);
	min = va_arg(num_list, int);
	i = 0;
	while (++i < total_num)
	{
		num = va_arg(num_list, int);
		if (num < min)
			min = num;
	}
	va_end(num_list);
	return (min);
}
