/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 19:38:07 by zwang             #+#    #+#             */
/*   Updated: 2018/09/27 19:03:12 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	atol_result(int sign, unsigned long num)
{
	long	long_lim;

	long_lim = 9223372036854775807;
	if (sign > 0 && num >= (unsigned long)long_lim)
		return (long_lim);
	if (sign < 0 && num - 1 >= (unsigned long)long_lim)
		return (-long_lim - 1);
	return ((long)num * sign);
}

long		ft_atol(const char *str)
{
	unsigned long	num;
	int				sign;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	return (atol_result(sign, num));
}
