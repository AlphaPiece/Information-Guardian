/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 19:19:14 by zwang             #+#    #+#             */
/*   Updated: 2018/07/16 09:49:15 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	i = 0;
	while (*ptr)
	{
		ptr++;
		i++;
	}
	while ((int)(i--) >= 0)
	{
		if (*ptr == c)
			return (ptr);
		--ptr;
	}
	return (NULL);
}
