/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:36:31 by zwang             #+#    #+#             */
/*   Updated: 2018/09/19 20:51:12 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlstr(const char *str, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (str[start + i] && i < len)
		ft_putchar(str[start + i++]);
}
