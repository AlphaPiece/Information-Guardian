/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 13:04:45 by zwang             #+#    #+#             */
/*   Updated: 2018/08/21 20:37:43 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	if (!(*s))
		return ("");
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	len = ft_strlen(s) - 1;
	while (len > i && (s[len] == ' ' || s[len] == '\t' || s[len] == '\n'))
		len--;
	if (len < i)
		return (ft_strdup(""));
	return (ft_strsub(s, i, len - i + 1));
}
