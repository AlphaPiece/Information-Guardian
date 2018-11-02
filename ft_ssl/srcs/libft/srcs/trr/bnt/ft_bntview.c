/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bntview.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:47:03 by zwang             #+#    #+#             */
/*   Updated: 2018/10/01 09:40:50 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define COUNT	10

void	bntview(t_btree *bnt, int space, char type)
{	
	if (!bnt)
		return ;
	space += COUNT;
	bntview(bnt->right, space, type);
	ft_putchar('\n');
	ft_putnchar(' ', space - COUNT);
	if (type == 'n')
		ft_printf("%d\n", *((int *)bnt->data));
	else if (type == 's')
		ft_printf("%s\n", (char *)bnt->data);
	bntview(bnt->left, space, type);
}

void	ft_bntview(t_btree *bnt, char type)
{
	bntview(bnt, 0, type);
}
