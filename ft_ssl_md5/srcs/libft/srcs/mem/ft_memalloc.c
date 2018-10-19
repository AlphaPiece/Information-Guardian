/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:18:31 by zwang             #+#    #+#             */
/*   Updated: 2018/07/15 20:59:43 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*cpy;

	if ((ptr = malloc(size)))
	{
		cpy = (char *)ptr;
		while (size--)
			cpy[size] = 0;
	}
	return (ptr);
}
