/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:48:26 by zwang             #+#    #+#             */
/*   Updated: 2018/09/27 19:03:58 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	atol_base_result(int sign, unsigned long num)
{
	long	long_lim;

	long_lim = 9223372036854775807;
	if (sign > 0 && num >= (unsigned long)long_lim)
		return (long_lim);
	if (sign < 0 && num - 1 >= (unsigned long)long_lim)
		return (-long_lim - 1);
	return ((long)num * sign);
}

long		ft_atol_base(const char *str, int base)
{
	unsigned long	num;
	int				sign;

	if (base < 2 || base > 16)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	if (base <= 10)
		while (*str >= '0' && *str <= base - 1 + '0')
			num = num * base + *str++ - '0';
	else
		while ((*str >= '0' && *str <= '9') ||
				(*str >= 'A' && *str <= base - 11 + 'A') ||
				(*str >= 'a' && *str <= base - 11 + 'a'))
			if (*str >= '0' && *str <= '9')
				num = num * base + *str++ - '0';
			else if (*str >= 'A' && *str <= base - 11 + 'A')
				num = num * base + *str++ - 'A' + 10;
			else
				num = num * base + *str++ - 'a' + 10;
	return (atol_base_result(sign, num));
}
