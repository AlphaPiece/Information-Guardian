/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 09:21:54 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:48:30 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vdprintf.h"

static void	hash_modifier(t_package *package, uintmax_t num)
{
	if (num != 0 || package->fmt_spfr == 'p')
	{
		if (package->fmt_spfr == 'o')
		{
			if (package->precision > 2)
				package->precision--;
			if (package->width > 2)
				package->width--;
		}
		else if (package->fmt_spfr == 'x' || package->fmt_spfr == 'p')
		{
			if (package->width > 2)
				package->width -= 2;
		}
	}
}

static void	inner_process(t_package *package, t_strblock *block, uintmax_t num)
{
	if (package->collection['#'])
		hash_modifier(package, num);
	if (package->collection['-'])
	{
		package->collection['0'] = 0;
		hash_handler(package, block, num);
		int_precision_handler(package, block);
		content_handler(package, block);
		width_handler(package, block);
	}
	else
	{
		if (package->collection['0'])
		{
			hash_handler(package, block, num);
			width_handler(package, block);
		}
		else
		{
			width_handler(package, block);
			hash_handler(package, block, num);
		}
		int_precision_handler(package, block);
		content_handler(package, block);
	}
}

void		unsigned_integer(t_package *package, va_list args)
{
	uintmax_t	num;
	t_strblock	*block;

	num = modify_unsigned_integer(package, args);
	if (package->fmt_spfr == 'o' || package->fmt_spfr == 'O')
		package->part = ft_untoa_base(num, 8, '\0');
	else if (package->fmt_spfr == 'u' || package->fmt_spfr == 'U')
		package->part = ft_untoa(num);
	else if (package->fmt_spfr == 'x' || package->fmt_spfr == 'p')
		package->part = ft_untoa_base(num, 16, 'a');
	else if (package->fmt_spfr == 'X')
		package->part = ft_untoa_base(num, 16, 'A');
	package->part_len = ft_strlen(package->part);
	package->collection['+'] = 0;
	package->collection[' '] = 0;
	block = find_last_block(package->strchain);
	inner_process(package, block, num);
	free(package->part);
}
