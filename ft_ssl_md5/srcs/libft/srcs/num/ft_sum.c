/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 15:09:30 by zwang             #+#    #+#             */
/*   Updated: 2018/09/28 16:24:15 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sum(int total_num, ...)
{
	va_list	num_list;
	int		i;
	int		sum;

	va_start(num_list, total_num);
	sum = 0;
	i = 0;
	while (i++ < total_num)
		sum += va_arg(num_list, int);
	va_end(num_list);
	return (sum);
}
