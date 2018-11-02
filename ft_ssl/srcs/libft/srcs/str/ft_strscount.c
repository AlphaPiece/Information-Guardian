/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:13:17 by zwang             #+#    #+#             */
/*   Updated: 2018/09/20 16:34:08 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strscount: count # of substrings of str which matches s
*/

size_t	ft_strscount(const char *str, const char *s)
{
	size_t	count;
	int		i;
	int		j;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == s[0])
		{
			j = 1;
			while (str[i + j] && s[j] && str[i + j] == s[j])
				++j;
			if (!s[j])
				++count;
		}
		++i;
	}
	return (count);
}
