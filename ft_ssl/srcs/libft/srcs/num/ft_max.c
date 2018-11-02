/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 22:41:52 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 09:34:50 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int total_num, ...)
{
	va_list	num_list;
	int		i;
	int		num;
	int		max;

	va_start(num_list, total_num);
	i = 0;
	max = va_arg(num_list, int);
	while (++i < total_num)
	{
		num = va_arg(num_list, int);
		if (num > max)
			max = num;
	}
	va_end(num_list);
	return (max);
}
