/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 14:49:03 by zwang             #+#    #+#             */
/*   Updated: 2018/07/15 16:01:58 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	char	*ptr1;
	char	*ptr2;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	ptr = (char *)haystack;
	while (*ptr)
	{
		if (*needle == *ptr)
		{
			ptr1 = ptr;
			ptr2 = (char *)needle;
			while (*ptr2 && *ptr1 == *ptr2)
			{
				ptr1++;
				ptr2++;
			}
			if (!(*ptr2))
				return (ptr);
		}
		ptr++;
	}
	return (NULL);
}
