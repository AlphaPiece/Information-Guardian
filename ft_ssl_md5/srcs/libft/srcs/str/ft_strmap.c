/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:03:27 by zwang             #+#    #+#             */
/*   Updated: 2018/09/22 17:43:56 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ns;
	int		i;

	if (!s || !*s || !f ||
			!(ns = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		ns[i] = f(s[i]);
	ns[i] = '\0';
	return (ns);
}
