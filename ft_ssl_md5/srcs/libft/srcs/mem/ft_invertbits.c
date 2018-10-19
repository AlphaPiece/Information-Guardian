/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invertbits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:32:17 by zwang             #+#    #+#             */
/*   Updated: 2018/09/24 18:28:14 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Assumption: bit position 0 is at the right end
**
** ft_invertbits: invert the n bits that begin at position p
*/

unsigned int	ft_invertbits(unsigned int x, int p, int n)
{
	unsigned int	part1;
	unsigned int	part2;
	unsigned int	part3;

	part1 = (x >> (p + 1)) << (p + 1);
	part2 = ~x & (~(~0 << n) << (p + 1 - n));
	part3 = x & ~(~0 << (p + 1 -n));
	return (part1 | part2 | part3);
}
