/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 09:21:40 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:48:12 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vdprintf.h"

static void	inner_process(t_package *package, t_strblock *block, intmax_t num)
{
	if (package->collection['-'])
	{
		package->collection['0'] = 0;
		sign_handler(package, block, num);
		int_precision_handler(package, block);
		content_handler(package, block);
		width_handler(package, block);
	}
	else
	{
		if (package->collection['0'])
		{
			sign_handler(package, block, num);
			width_handler(package, block);
		}
		else
		{
			width_handler(package, block);
			sign_handler(package, block, num);
		}
		int_precision_handler(package, block);
		content_handler(package, block);
	}
}

/*
** '_' indicates that the number is negative.
*/

void		signed_integer(t_package *package, va_list args)
{
	intmax_t	num;
	t_strblock	*block;
	char		*tmp;

	num = modify_signed_integer(package, args);
	package->part = ft_ntoa(num);
	package->part_len = ft_strlen(package->part);
	if (num < 0)
	{
		package->collection['_'] = 1;
		tmp = package->part;
		package->part = ft_strsub(package->part, 1, --(package->part_len));
		free(tmp);
	}
	if (package->collection['.'])
		package->collection['0'] = 0;
	block = find_last_block(package->strchain);
	inner_process(package, block, num);
	free(package->part);
}
