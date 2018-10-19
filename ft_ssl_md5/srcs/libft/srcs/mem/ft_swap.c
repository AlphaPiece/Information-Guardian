/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 08:48:15 by zwang             #+#    #+#             */
/*   Updated: 2018/10/19 12:36:31 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap8b(t_ptr *ptr1, t_ptr *ptr2, void *n1, void *n2)
{
	uint8_t		tmp;

	ptr1->uint8p = (uint8_t *)n1;
	ptr2->uint8p = (uint8_t *)n2;
	tmp = *ptr1->uint8p;
	*ptr1->uint8p = *ptr2->uint8p;
	*ptr2->uint8p = tmp;
}

static void	swap16b(t_ptr *ptr1, t_ptr *ptr2, void *n1, void *n2)
{
	uint16_t	tmp;

	ptr1->uint16p = (uint16_t *)n1;
	ptr2->uint16p = (uint16_t *)n2;
	tmp = *ptr1->uint16p;
	*ptr1->uint16p = *ptr2->uint16p;
	*ptr2->uint16p = tmp;
}

static void	swap32b(t_ptr *ptr1, t_ptr *ptr2, void *n1, void *n2)
{
	uint32_t	tmp;
	
	ptr1->uint32p = (uint32_t *)n1;
	ptr2->uint32p = (uint32_t *)n2;
	tmp = *ptr1->uint32p;
	*ptr1->uint32p = *ptr2->uint32p;
	*ptr2->uint32p = tmp;
}

static void	swap64b(t_ptr *ptr1, t_ptr *ptr2, void *n1, void *n2)
{
	uint64_t	tmp;
	
	ptr1->uint64p = (uint64_t *)n1;
	ptr2->uint64p = (uint64_t *)n2;
	tmp = *ptr1->uint64p;
	*ptr1->uint64p = *ptr2->uint64p;
	*ptr2->uint64p = tmp;
}

void		ft_swap(size_t byte, void *n1, void *n2)
{
	t_ptr	ptr1;
	t_ptr	ptr2;

	if (byte == BIT8)
		swap8b(&ptr1, &ptr2, n1, n2);
	else if (byte == BIT16)
		swap16b(&ptr1, &ptr2, n1, n2);
	else if (byte == BIT32)
		swap32b(&ptr1, &ptr2, n1, n2);
	else if (byte == BIT64)
		swap64b(&ptr1, &ptr2, n1, n2);
	else
		ft_dprintf(2, "error: invalid input for byte\n");
}
