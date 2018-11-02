/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_untoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:39:27 by zwang             #+#    #+#             */
/*   Updated: 2018/08/19 14:14:50 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	inner_process(uintmax_t un, int base, char **ptr, char hex_case_a)
{
	char	r;

	if (un >= (unsigned int)base)
		inner_process(un / base, base, ptr, hex_case_a);
	r = (char)ABS(un % base);
	if (r < 10)
		*(*ptr)++ = r + '0';
	else
		*(*ptr)++ = r - 10 + hex_case_a;
}

char		*ft_untoa_base(uintmax_t un, int base, char hex_case_a)
{
	char	*str;
	int		len;
	char	*ptr;

	if (base < 2 || base > 16 || (hex_case_a &&
		hex_case_a != 'a' && hex_case_a != 'A'))
		return (NULL);
	len = ft_unumlen(un);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = str;
	inner_process(un, base, &ptr, hex_case_a);
	*ptr = '\0';
	return (str);
}
