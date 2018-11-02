/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:58:32 by zwang             #+#    #+#             */
/*   Updated: 2018/07/15 16:02:11 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)haystack;
	if (!(*needle))
		return (ptr);
	i = 0;
	while (*(ptr + i) && i < len)
	{
		if (*needle == *(ptr + i))
		{
			j = 0;
			while (*(needle + j) && *(ptr + i + j) == *(needle + j)
					&& i + j < len)
				j++;
			if (!(*(needle + j)))
				return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
