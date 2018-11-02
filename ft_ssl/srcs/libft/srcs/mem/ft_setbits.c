/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:48:59 by zwang             #+#    #+#             */
/*   Updated: 2018/09/24 17:42:35 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Assumption: bit position 0 is at the right end
**
** ft_setbits: returns with the n bits that begin at position p
** 			   set to the rightmost n bits of y, leaving the other
**			   bits unchanged
*/

unsigned int	ft_setbits(unsigned int x, int p, int n, unsigned int y)
{
	unsigned int	part1;
	unsigned int	part2;
	unsigned int	part3;

	part1 = (y & ~(~0 << n)) << (p + 1 - n);
	part2 = ((x >> (p + 1)) & ~0) << (p + 1);
	part3 = x & ~(~0 << (p + 1 - n));
	return (part1 | part2 | part3);
}
