/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 09:33:37 by zwang             #+#    #+#             */
/*   Updated: 2018/09/19 10:10:07 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fcompo	*ft_analyze_float(float n)
{
	t_fcompo		*fcompo;
	long			*nbr;

	if (!(fcompo = (t_fcompo *)malloc(sizeof(t_fcompo))))
		return (NULL);
	nbr = (long *)&n;
	fcompo->mantissa = *nbr & 0x7FFFFF;
	fcompo->mantissa |= 0x800000;
	fcompo->exponent = ((*nbr >> 23) & 0xFF) - 0x7F;
	fcompo->sign = (*nbr >> 31) & 0x1;
	return (fcompo);
}
