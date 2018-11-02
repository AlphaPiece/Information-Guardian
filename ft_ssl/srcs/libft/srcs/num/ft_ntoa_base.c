/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 09:41:18 by zwang             #+#    #+#             */
/*   Updated: 2018/08/19 14:16:15 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	inner_process(intmax_t n, int base, char **ptr, char hex_case_a)
{
	char	r;

	if (n <= -base || n >= base)
		inner_process(n / base, base, ptr, hex_case_a);
	r = (char)ABS(n % base);
	if (r < 10)
		*(*ptr)++ = r + '0';
	else
		*(*ptr)++ = r - 10 + hex_case_a;
}

char		*ft_ntoa_base(intmax_t n, int base, char hex_case_a)
{
	char	*str;
	int		len;
	char	*ptr;

	if (base < 2 || base > 16 || (hex_case_a &&
		hex_case_a != 'a' && hex_case_a != 'A'))
		return (NULL);
	len = ft_numlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ptr = str;
	if (base == 10 && n < 0)
		*ptr++ = '-';
	inner_process(n, base, &ptr, hex_case_a);
	*ptr = '\0';
	return (str);
}
