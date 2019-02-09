/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:41:04 by zwang             #+#    #+#             */
/*   Updated: 2019/02/09 13:04:54 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** sublen: # of bytes of a portion of the string
** bitlen: # of bits of the whole string
*/

void	md5_process(uint32_t *stream, uint64_t sublen, uint64_t bitlen,
					char *input)
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
	md5_postprocess(input);
}

void	md5_str(char *msg)
{
	uint64_t	sublen;
	uint64_t	bitlen;
	char		*input;
	
	sublen = ft_strlen(msg);
	bitlen = sublen * 8;
	input = ft_strcompose(3, "\"", msg, "\"");
	md5_process((uint32_t *)msg, sublen, bitlen, input);
	free(input);
}

void	md5_file(char *name)
{
	uint32_t	buf[16];
	int			fd;
	uint64_t	sublen;
	uint64_t	bitlen;

	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_printf("ft_ssl: No such file or directory\n");
		exit(1);
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
	md5_process(buf, sublen, bitlen, name);	
}
