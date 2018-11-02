/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 14:34:09 by zwang             #+#    #+#             */
/*   Updated: 2018/09/18 21:51:53 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vdprintf.h"

static t_handler	g_handler_table[HANDLER_NUM] = \
{
	{"c%", character},
	{"s", string},
	{"diD", signed_integer},
	{"ouxOUXp", unsigned_integer}
};

static void			inner_process(t_package *package, char *ptr, int *i)
{
	if (ptr[*i] == '0' && (*i == 0 || (*i > 0 && !ft_isdigit(ptr[*i - 1]))))
		package->collection[(int)(ptr[(*i)++])] = 1;
	else if (ft_isdigit(ptr[*i]) && (*i == 0 || (*i > 0 && ptr[*i - 1] != '.')))
	{
		package->width = ft_atoi(&ptr[*i]);
		(*i) += ft_numlen(package->width);
	}
	else if (ptr[*i] == '.' && ft_isdigit(ptr[*i + 1]))
	{
		package->collection['.'] = 1;
		package->precision = ft_atoi(&ptr[*i + 1]);
		(*i) += (ft_numlen(package->precision) + 1);
	}
	else if (is_flag(ptr[*i]))
		package->collection[(int)(ptr[(*i)++])] = 1;
	else if (is_modifier(ptr[*i]))
		package->collection[(int)(ptr[(*i)++])] += 1;
	else
		(*i)++;
}

char				*flag_collector(t_package *package, char *ptr, va_list args)
{
	int		i;

	i = 0;
	while (ptr[i] && !is_conversion(ptr[i]))
	{
		if (ptr[i] == '*')
			asterisk_handler(package, ptr, &i, args);
		else
			inner_process(package, ptr, &i);
	}
	if (!is_conversion(ptr[i]))
		return (NULL);
	return (&ptr[i]);
}

static void			interpret_fmt_spfr(t_package *package, char *fmt_spfr)
{
	if (*fmt_spfr == 'D' || *fmt_spfr == 'O' || *fmt_spfr == 'U')
		package->collection['l']++;
	if (*fmt_spfr == 'p')
	{
		package->collection['#'] = 1;
		package->collection['l']++;
	}
}

/*
** fmt_ptr points to the character just after the %.
*/

char				*fmt_handler(t_package *package, char *fmt_ptr,
									va_list args)
{
	char	*fmt_spfr;
	int		i;

	package->width = 0;
	package->precision = -1;
	initialize_zero(package->collection);
	fmt_spfr = flag_collector(package, fmt_ptr, args);
	if (!fmt_spfr)
		return (fmt_ptr);
	interpret_fmt_spfr(package, fmt_spfr);
	package->fmt_spfr = *fmt_spfr;
	i = -1;
	while (++i < HANDLER_NUM)
		if (ft_strchr(g_handler_table[i].fmt_spfr, package->fmt_spfr))
		{
			g_handler_table[i].handler(package, args);
			break ;
		}
	return (fmt_spfr + 1);
}
