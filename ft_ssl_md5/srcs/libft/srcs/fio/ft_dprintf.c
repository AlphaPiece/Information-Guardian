/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 21:54:39 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:56:57 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		total_char;

	va_start(args, format);
	total_char = ft_vdprintf(fd, format, args);
	va_end(args);
	return (total_char);
}
