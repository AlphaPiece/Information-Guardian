/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 18:56:54 by zwang             #+#    #+#             */
/*   Updated: 2018/07/15 16:07:22 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((!(*s1) && !(*s2)) || n == 0)
		return (0);
	if (*s1 != *s2)
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
