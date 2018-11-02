/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 16:57:59 by zwang             #+#    #+#             */
/*   Updated: 2018/07/15 11:00:51 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	dup = ft_strcpy(dup, s);
	return (dup);
}
