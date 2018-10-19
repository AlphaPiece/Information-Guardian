/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:46:52 by zwang             #+#    #+#             */
/*   Updated: 2018/09/24 17:39:36 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Assumption: bit position 0 is at the right end
**
** ft_getbits: return the (right-adjusted) n-bit field of x from position p
*/

unsigned int	ft_getbits(unsigned int x, int p, int n)
{
	return ((x >> (p + 1 - n)) & ~(~0 << n));
}
