/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:16:00 by zwang             #+#    #+#             */
/*   Updated: 2019/04/06 21:40:32 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	execute_op_p(int argc, char **argv, t_op *op)
{
	char	buf[BUF_SIZ];
	char	*msg;
	char	*tmp;

	msg = "";
	while (read(1, buf, BUF_SIZ) > 0)
	{
		tmp = msg;
		msg = ft_strjoin(msg, buf);
		if (*tmp)
			free(tmp);
	}
	if (*msg)
	{
		md5_str(msg, op);
		free(msg);
	}
}

int		parse_op(int argc, char **argv, t_op *op)
{
	int	c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
			if (c == 's')
			{
				if (!*(argv[0] + 1) && !argv[1])
				{
					ft_printf("md5: option requires an argument -- s\n");
					return (1);
				}
				op->s = true;
				if (*++argv[0])
					md5_str(argv[0], op);
				else
				{
					--argc;
					md5_str(*++argv, op);
				}
				break ;
			}
			else if (c == 'q')
				op->q = true;
			else if (c == 'p')
			{
				op->p = true;
				execute_op_p(argc, argv, op);
				op->p = false;
			}
			else if (c == 'r')
				op->r = true;
	while (argc-- > 0)
		md5_file(*argv++, op);
	return (0);
}

int		parse_stdin(char *algo)
{
	char		*input;
	char		*tmp;
	char		buf[51];
	uint64_t	len;

	if (IS_MD5(algo))
	{
		input = "";
		while ((len = read(1, buf, 50)) > 0)
		{
			buf[len] = '\0';
			tmp = input;
			input = ft_strjoin(input, buf);
			if (*tmp)
				free(tmp);
		}
		if (*input)
		{
			len = ft_strlen(input);
			md5_process((uint32_t *)input, len, len * 8);
			md5_passcode();
			free(input);
		}
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_op	op;
	int		flag;

	flag = 1;
	if (argc == 2)
		flag = parse_stdin(argv[1]);
	if (--argc >= 2 && IS_MD5(*++argv))
	{
		op.s = false;
		op.q = false;
		op.p = false;
		op.r = false;
		flag = parse_op(argc, argv, &op);
	}
	if (flag)
		ft_printf("usage: ./ft_ssl [md5] [-pqrs] [string | file]\n");
	return (0);
}
