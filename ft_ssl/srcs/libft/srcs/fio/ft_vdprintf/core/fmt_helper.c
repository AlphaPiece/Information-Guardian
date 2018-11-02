/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 14:32:33 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:41:43 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vdprintf.h"

void	initialize_zero(char collection[127])
{
	collection['#'] = 0;
	collection['+'] = 0;
	collection['-'] = 0;
	collection['_'] = 0;
	collection['0'] = 0;
	collection[' '] = 0;
	collection['.'] = 0;
	collection['h'] = 0;
	collection['l'] = 0;
	collection['j'] = 0;
	collection['z'] = 0;
}

int		is_conversion(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%');
}

int		is_flag(char c)
{
	return (c == '#' || c == '+' || c == '-' || c == ' ' || c == '.');
}

int		is_modifier(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 't' || c == 'z');
}

void	asterisk_handler(t_package *package, char *ptr, int *i, va_list args)
{
	if (ptr[*i] == '*' && (*i == 0 || (*i > 0 && ptr[*i - 1] != '.')))
	{
		package->width = va_arg(args, int);
		if (package->width < 0)
		{
			package->width = -(package->width);
			package->collection['-'] = 1;
		}
		(*i)++;
	}
	else if (ptr[*i] == '*' && *i > 0 && ptr[*i - 1] == '.')
	{
		package->precision = va_arg(args, int);
		if (package->precision < 0)
		{
			package->collection['.'] = 0;
			package->precision = 0;
		}
		(*i)++;
	}
}
