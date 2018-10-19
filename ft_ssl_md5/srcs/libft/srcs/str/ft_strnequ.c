/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 09:46:25 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 10:31:03 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (false);
	if ((!(*s1) && !(*s2)) || n == 0)
		return (true);
	if (*s1 != *s2)
		return (false);
	return (ft_strnequ(s1 + 1, s2 + 1, n - 1));
}
