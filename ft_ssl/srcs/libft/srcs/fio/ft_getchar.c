/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 19:34:06 by zwang             #+#    #+#             */
/*   Updated: 2018/10/13 13:25:34 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		new_getchar(void)
{
	static char	buf[BUF_SIZ];
	static char	*bufp = buf;
	static int	n = 0;

	if (n == 0)
	{
		n = read(0, buf, sizeof(buf));
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char) *bufp++ : -1);
}
