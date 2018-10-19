/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aswap_bswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:27:31 by zwang             #+#    #+#             */
/*   Updated: 2018/09/22 16:10:43 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_aswap: swap using arithmetic operations
*/

void	ft_aswap(int *n1, int *n2)
{
	*n1 = *n1 + *n2;
	*n2 = *n1 - *n2;
	*n1 = *n1 - *n2;
}

/*
** ft_bswap: swap using bitwise operations
*/

void	ft_bswap(int *n1, int *n2)
{
	*n1 = *n1 ^ *n2;
	*n2 = *n1 ^ *n2;
	*n1 = *n1 ^ *n2;
}
