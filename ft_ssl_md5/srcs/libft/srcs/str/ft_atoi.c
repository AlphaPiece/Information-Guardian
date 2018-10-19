/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:52:55 by zwang             #+#    #+#             */
/*   Updated: 2018/09/27 19:02:34 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_result(long num)
{
	long	long_lim;

	long_lim = 9223372036854775807;
	if (num == long_lim)
		return (-1);
	if (num == -long_lim - 1)
		return (0);
	return ((int)num);
}

int			ft_atoi(const char *str)
{
	long	num;

	num = ft_atol(str);
	return (atoi_result(num));
}
