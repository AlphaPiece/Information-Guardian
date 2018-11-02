/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:03:49 by zwang             #+#    #+#             */
/*   Updated: 2018/09/19 14:23:21 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strend(const char *str, const char *substr)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(substr);
	if (ft_strlen(str) < len)
		return (false);
	while (*str)
		str++;
	while (*substr)
		substr++;
	i = 0;
	while (i++ < len)
		if (*str-- != *substr--)
			return (false);
	return (true);
}
