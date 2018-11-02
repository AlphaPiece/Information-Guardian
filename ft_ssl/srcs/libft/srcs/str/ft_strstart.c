/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:04:11 by zwang             #+#    #+#             */
/*   Updated: 2018/09/19 14:05:34 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strstart(const char *str, const char *substr)
{
	size_t	i;

	i = 0;
	while (str[i] && substr[i])
	{
		if (str[i] != substr[i])
			break ;
		i++;
	}
	return (i == ft_strlen(substr));
}
