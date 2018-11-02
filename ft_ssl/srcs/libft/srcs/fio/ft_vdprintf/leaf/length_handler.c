/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:07:12 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:47:08 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vdprintf.h"

intmax_t	modify_signed_integer(t_package *package, va_list args)
{
	intmax_t	num;

	if (package->collection['j'] >= 1)
		num = va_arg(args, intmax_t);
	else if (package->collection['l'] >= 2)
		num = va_arg(args, long long);
	else if (package->collection['l'] == 1)
		num = va_arg(args, long);
	else if (package->collection['z'] >= 1)
		num = va_arg(args, ssize_t);
	else if (package->collection['h'] == 1)
		num = (signed short)va_arg(args, int);
	else if (package->collection['h'] >= 2)
		num = (signed char)va_arg(args, int);
	else
		num = va_arg(args, int);
	return (num);
}

uintmax_t	modify_unsigned_integer(t_package *package, va_list args)
{
	uintmax_t	num;

	if (package->collection['j'] >= 1)
		num = va_arg(args, uintmax_t);
	else if (package->collection['l'] >= 2)
		num = va_arg(args, unsigned long long);
	else if (package->collection['l'] == 1)
		num = va_arg(args, unsigned long);
	else if (package->collection['z'] >= 1)
		num = va_arg(args, size_t);
	else if (package->collection['h'] == 1)
		num = (unsigned short)va_arg(args, int);
	else if (package->collection['h'] >= 2)
		num = (unsigned char)va_arg(args, int);
	else
		num = va_arg(args, unsigned int);
	return (num);
}
