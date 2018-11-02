/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 16:30:13 by zwang             #+#    #+#             */
/*   Updated: 2018/09/20 16:11:50 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	str_num;

	str_num = ft_strccount(s, c);
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (str_num + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < str_num)
	{
		arr[i] = ft_strnew(ft_strclen(&s[k], c) + 1);
		while (s[k] && s[k] == c)
			k++;
		j = 0;
		while (s[k] && s[k] != c)
			arr[i][j++] = s[k++];
		arr[i++][j] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}
