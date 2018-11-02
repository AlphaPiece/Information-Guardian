/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iselem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:06:48 by zwang             #+#    #+#             */
/*   Updated: 2018/10/19 12:38:56 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set16b(t_ptr *ap, t_ptr *np, void *arr, void *num)
{
	ap->uint16p = (uint16_t *)arr;
	np->uint16p = (uint16_t *)num;
}

static void	set32b(t_ptr *ap, t_ptr *np, void *arr, void *num)
{
	ap->uint32p = (uint32_t *)arr;
	np->uint32p = (uint32_t *)num;
}

static void	set64b(t_ptr *ap, t_ptr *np, void *arr, void *num)
{
	ap->uint64p = (uint64_t *)arr;
	np->uint64p = (uint64_t *)num;
}

t_bool		ft_iselem(size_t byte, void *arr, size_t len, void *num)
{
	int		i;
	t_ptr	ap;
	t_ptr	np;

	if (byte == BIT16)
		set16b(&ap, &np, arr, num);
	else if (byte == BIT32)
		set32b(&ap, &np, arr, num);
	else if (byte == BIT64)
		set64b(&ap, &np, arr, num);
	else
	{
		ft_dprintf(2, "error: invalid input for byte\n");
		return (false);
	}
	i = -1;
	while ((size_t)(++i) < len)
		if (byte == BIT16 && ap.uint16p[i] == *np.uint16p)
			return (true);
		else if (byte == BIT32 && ap.uint32p[i] == *np.uint32p)
			return (true);
		else if (byte == BIT64 && ap.uint64p[i] == *np.uint64p)
			return (true);
	return (false);
}
