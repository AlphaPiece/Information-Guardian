/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:41:04 by zwang             #+#    #+#             */
/*   Updated: 2019/02/18 14:49:54 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

extern uint32_t	g_a0;
extern uint32_t	g_b0;
extern uint32_t	g_c0;
extern uint32_t	g_d0;

/*
** sublen: # of bytes of a portion of the string
** bitlen: # of bits of the whole string
*/

void	md5_process(uint32_t *stream, uint64_t sublen, uint64_t bitlen)
{
	uint64_t	bufsiz;
	uint32_t	*buf;
	uint64_t	i;

	bufsiz = sublen;
	while (bufsiz % 64 != 0)
		bufsiz += 1;
	if (sublen > 56)
		bufsiz += 64;
	if (!(buf = md5_preprocess(stream, sublen, bitlen, bufsiz)))
		ft_dprintf(2, "preprocess: allocation failed\n");
	i = -1;
	while (++i < bufsiz / 64)
		md5_inprocess(buf + i * 16);
	free(buf);
}

void	md5_str(char *msg, t_op *op)
{
	uint64_t	sublen;
	uint64_t	bitlen;
	char		*input;

	sublen = ft_strlen(msg);
	bitlen = sublen * 8;
	if (!op->p)
		input = ft_strcompose(3, "\"", msg, "\"");
	else
		input = msg;
	md5_process((uint32_t *)msg, sublen, bitlen);
	md5_postprocess(input, op);
	if (!op->p)
		free(input);
}

void	md5_file(char *name, t_op *op)
{
	uint32_t	buf[16];
	int			fd;
	uint64_t	sublen;
	uint64_t	bitlen;

	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_printf("ft_ssl: file %s not found\n", name);
		return ;
	}
	ft_bzero(buf, 64);
	sublen = 0;
	bitlen = 0;
	while ((sublen = read(fd, buf, 64)) == 64)
	{
		md5_inprocess(buf);
		bitlen += 512;
		ft_bzero(buf, 64);
	}
	bitlen += sublen * 8;
	md5_process(buf, sublen, bitlen);
	md5_postprocess(name, op);
}

void	md5_reset(void)
{
	g_a0 = 0x67452301;
	g_b0 = 0xefcdab89;
	g_c0 = 0x98badcfe;
	g_d0 = 0x10325476;
}
