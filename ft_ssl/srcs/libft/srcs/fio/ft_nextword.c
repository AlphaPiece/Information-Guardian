/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:51:31 by zwang             #+#    #+#             */
/*   Updated: 2018/09/25 16:00:05 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Assumption: a word is either a string of letters and digits beginning
**			   with a letter, or a single non-white space character
**
** Function-value: first character of the word, or EOF, or character itself
**				   if it is not alphabetic
*/

int		ft_nextword(char *word, int limit)
{
	int		c;
	char	*w;

	w = word;
	while (ft_isspace(c = ft_nextchar()))
		;
	if (c >= 0)
		*w++ = c;
	if (!ft_isalpha(c))
	{
		*w = '\0';
		return (c);
	}
	while (--limit)
	{
		if (!ft_isalnum(*w = ft_nextchar()))
		{
			ft_savechar(*w);
			break ;
		}
		w++;
	}
	*w = '\0';
	return (word[0]);
}
