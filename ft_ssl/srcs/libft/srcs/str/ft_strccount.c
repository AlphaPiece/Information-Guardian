/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:38:22 by zwang             #+#    #+#             */
/*   Updated: 2018/09/20 16:34:31 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

enum	e_state {OUT, IN};

/*
** ft_strcount: count # of substrings of s separated by c
*/

size_t	ft_strccount(const char *s, char c)
{
	size_t			count;
	enum e_state	state;

	if (!s || !*s)
		return (0);
	state = OUT;
	count = (*s == c) ? 0 : 1;
	while (*s)
	{
		if (*s == c)
			state = IN;
		else if (state == IN)
		{
			state = OUT;
			++count;
		}
		s++;
	}
	return (count);
}
