/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_afree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 10:29:35 by zwang             #+#    #+#             */
/*   Updated: 2018/09/24 18:04:56 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ALLOCSIZE:	size of available space
*/

#define ALLOCSIZE	10000

/*
** g_allocbuf:	storage for alloc
** g_allocptr:	pointer to next free position
*/

static char	g_allocbuf[ALLOCSIZE];
static char	*g_allocptr = g_allocbuf;

char	*alloc(int n)
{
	if (g_allocbuf + ALLOCSIZE - g_allocptr >= n)
	{
		g_allocptr += n;
		return (g_allocptr - n);
	}
	else
		return (NULL);
}

void	afree(char *p)
{
	if (p >= g_allocbuf && p < g_allocbuf + ALLOCSIZE)
		g_allocptr = p;
}
