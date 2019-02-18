/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:16:00 by zwang             #+#    #+#             */
/*   Updated: 2019/02/18 14:52:27 by Zexi Wang        ###   ########.fr       */
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

void	parse_op(int argc, char **argv, t_op *op)
{
	int	c;

	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
			if (c == 's')
			{
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
}

int		main(int argc, char **argv)
{
	t_op	op;

	if (--argc >= 2 && IS_MD5(*++argv))
	{
		op.s = false;
		op.q = false;
		op.p = false;
		op.r = false;
		parse_op(argc, argv, &op);
	}
	else
		ft_printf("usage: ./ft_ssl [md5] [-s] [string | file]\n");
	return (0);
}
