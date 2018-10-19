/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_brackets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 18:37:03 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 10:36:35 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define IS_OPEN(c) (c == '(' || c == '[' || c == '{')
#define IS_CLOSE(c) (c == ')' || c == ']' || c == '}')

/*
** b[0] : '('
** b[1] : ')'
** b[2] : '['
** b[3] : ']'
** b[4] : '{'
** b[5] : '}'
*/

static t_bool	bracket_num_match(const char *s)
{
	int		b[6];
	int		i;

	i = -1;
	while (++i < 6)
		b[i] = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '(')
			b[0]++;
		else if (s[i] == ')')
			b[1]++;
		else if (s[i] == '[')
			b[2]++;
		else if (s[i] == ']')
			b[3]++;
		else if (s[i] == '{')
			b[4]++;
		else if (s[i] == '}')
			b[5]++;
	}
	if (b[0] != b[1] || b[2] != b[3] || b[4] != b[5])
		return (false);
	return (true);
}

static char		get_matched_bracket(char open)
{
	char	close;

	close = '\0';
	if (open == '(')
		close = ')';
	else if (open == '[')
		close = ']';
	else if (open == '{')
		close = '}';
	return (close);
}

static t_bool	checking_process(const char *s, char open)
{
	char	close;

	close = get_matched_bracket(open);
	while (*s)
	{
		if (*s == close)
			return (true);
		else if (IS_CLOSE(*s))
			return (false);
		else if (IS_OPEN(*s))
			return (checking_process(s + 1, *s));
		s++;
	}
	return (false);
}

t_bool			ft_check_brackets(const char *s)
{
	int		matched;

	if (!bracket_num_match(s))
		return (false);
	matched = 1;
	while (*s)
	{
		if (IS_OPEN(*s))
			matched = checking_process(s + 1, *s);
		if (!matched)
			return (false);
		s++;
	}
	return (true);
}
