/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 18:16:00 by zwang             #+#    #+#             */
/*   Updated: 2018/09/27 18:59:06 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	int_part;
	double	deci_part;
	int		len;

	int_part = (double)ft_atoi(str);
	while (*str && *(str - 1) != '.')
		str++;
	deci_part = (double)ft_atoi(str);
	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	while (len--)
		deci_part /= 10;
	return (int_part + ((int_part > 0) ? deci_part : -deci_part));
}
