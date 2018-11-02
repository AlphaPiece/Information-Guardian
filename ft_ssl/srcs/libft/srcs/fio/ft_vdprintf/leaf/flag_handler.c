/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:32:29 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:22:09 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vdprintf.h"

void		hash_handler(t_package *package, t_strblock *block, uintmax_t num)
{
	if (package->collection['#'] && (num != 0 || package->fmt_spfr == 'p'))
	{
		if (package->fmt_spfr == 'o' || package->fmt_spfr == 'x' ||
			package->fmt_spfr == 'X' || package->fmt_spfr == 'p')
			block->str[block->storage++] = '0';
		if (package->fmt_spfr == 'x' || package->fmt_spfr == 'p')
			block->str[block->storage++] = 'x';
		else if (package->fmt_spfr == 'X')
			block->str[block->storage++] = 'X';
		block->str[block->storage] = '\0';
	}
}

void		sign_handler(t_package *package, t_strblock *block,
							intmax_t num)
{
	char	flag;

	if (package->collection['+'] || package->collection[' '] || num < 0)
	{
		flag = (package->collection['+']) ? '+' : ' ';
		if (num < 0)
			flag = '-';
		if (block->storage >= STR_LEN)
			block = append_new_strblock(block);
		block->str[block->storage++] = flag;
		block->str[block->storage] = '\0';
	}
}

void		int_precision_handler(t_package *package, t_strblock *block)
{
	int		diff;

	if (package->collection['.'] && package->precision > 0)
	{
		diff = package->precision - (int)(package->part_len);
		while (diff-- > 0)
		{
			if (block->storage >= STR_LEN)
				block = append_new_strblock(block);
			block->str[block->storage++] = '0';
		}
		block->str[block->storage] = '\0';
	}
}

/*
** '_' indicates that the number is negative.
*/

void		width_handler(t_package *package, t_strblock *block)
{
	int		diff;
	int		sign;
	char	flag;
	int		max;

	if (package->width > 0)
	{
		sign = (package->collection['+'] || package->collection[' '] ||
				package->collection['_']) ? 1 : 0;
		flag = (package->collection['0'] && !package->collection['.']) ?
				'0' : ' ';
		max = sign + (((int)package->part_len > package->precision) ?
				(int)package->part_len : package->precision);
		if (package->fmt_spfr == 's')
			max = package->part_len;
		diff = package->width - max;
		while (diff-- > 0)
		{
			if (block->storage >= STR_LEN)
				block = append_new_strblock(block);
			block->str[block->storage++] = flag;
		}
		block->str[block->storage] = '\0';
	}
}

void		content_handler(t_package *package, t_strblock *block)
{
	size_t	len;

	if ((package->collection['.'] && !ft_strcmp(package->part, "0") &&
		(package->precision == 0 || package->precision == -1)))
	{
		if (package->width == 0 && package->collection['#'] &&
			package->fmt_spfr == 'o')
			block->str[block->storage++] = '0';
		else if (package->width > 0)
			block->str[block->storage++] = ' ';
		block->str[block->storage] = '\0';
		return ;
	}
	len = package->part_len;
	while (block->storage + len >= STR_LEN)
	{
		ft_strncpy(&block->str[block->storage], package->part,
					STR_LEN - block->storage);
		len -= (STR_LEN - block->storage);
		package->part += (STR_LEN - block->storage);
		block->storage = STR_LEN;
		block = append_new_strblock(block);
	}
	ft_strcpy(&block->str[block->storage], package->part);
	block->storage += len;
}
