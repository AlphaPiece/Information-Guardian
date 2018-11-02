/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 20:31:27 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:21:12 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_char;
	
	va_start(args, format);
	total_char = ft_vdprintf(1, format, args);
	va_end(args);
	return (total_char);
}
