/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:07:46 by zwang             #+#    #+#             */
/*   Updated: 2018/10/05 15:26:57 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Precondition: new size must be larger than the older size
*/

void	*ft_memrealloc(void *ptr, size_t size)
{
	void	*newptr;

	if (!(newptr = malloc(size)))
		return (NULL);
	newptr = ft_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}
