/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:00:41 by zwang             #+#    #+#             */
/*   Updated: 2018/09/27 20:04:02 by zwang            ###   ########.fr       */
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

int			ft_atoi_base(const char *str, int base)
{
	long	num;

	num = ft_atol_base(str, base);
	return (atoi_result(num));
}
