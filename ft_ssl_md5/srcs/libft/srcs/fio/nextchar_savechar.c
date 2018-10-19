/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nextchar_savechar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:59:33 by zwang             #+#    #+#             */
/*   Updated: 2018/10/13 13:24:42 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** g_buf: buffer for ft_savechar
** g_bufpos: next free position in g_buf
*/

static char	g_buf[BUF_SIZ];
static int	g_bufpos = 0;

int		ft_nextchar(void)
{
	return ((g_bufpos > 0) ? g_buf[--g_bufpos] : ft_getchar());
}

void	ft_savechar(int c)
{
	if (g_bufpos >= BUF_SIZ)
		ft_printf("ft_savechar: too many characters\n");
	else
		g_buf[g_bufpos++] = c;
}
