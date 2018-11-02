/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:05:12 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:23:24 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vdprintf.h"

void		str_handler(t_strblock *strchain, const char *next_part,
							char *percent)
{
	t_strblock	*block;
	size_t		len;

	block = find_last_block(strchain);
	if (block->storage + (len = ft_strlen(next_part)) > STR_LEN)
		block = append_new_strblock(strchain);
	if (percent)
	{
		ft_strncpy(&(block->str[block->storage]), next_part,
					percent - next_part);
		block->storage += percent - next_part;
	}
	else
	{
		ft_strcpy(&(block->str[block->storage]), next_part);
		block->storage += len;
	}
}
