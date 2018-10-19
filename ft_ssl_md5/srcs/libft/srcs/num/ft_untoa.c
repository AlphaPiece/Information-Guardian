/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_untoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:54:47 by zwang             #+#    #+#             */
/*   Updated: 2018/08/16 12:30:30 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_untoa(uintmax_t un)
{
	char		*str;
	size_t		i;

	i = ft_unumlen(un);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i--] = '\0';
	str[0] = '0';
	while (un > 0)
	{
		str[i--] = '0' + (un % 10);
		un /= 10;
	}
	return (str);
}
