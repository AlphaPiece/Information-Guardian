/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbitsln.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 19:26:10 by zwang             #+#    #+#             */
/*   Updated: 2018/09/24 15:46:31 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** iterative implementation
*/

void	ft_putbitsln(unsigned long n)
{
	unsigned long	i;
	unsigned long	one;

	one = 1;
	i = one << 63;
	while (i > 0)
	{
		(n & i) ? ft_putchar('1') : ft_putchar('0');
		i /= 2;
	}
	ft_putchar('\n');
}
