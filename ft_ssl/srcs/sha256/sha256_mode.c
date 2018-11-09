/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:47:15 by zwang             #+#    #+#             */
/*   Updated: 2018/11/08 19:42:32 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** sublen: # of bytes of a portion of the string
** bitlen: # of bits of the whole string
*/

void	sha256_process(uint32_t *stream, uint64_t sublen, uint64_t bitlen,
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
	if (!(buf = sha256_preprocess(stream, sublen, bitlen, bufsiz)))
		ft_dprintf(2, "preprocess: allocation failed\n");
	i = -1;
	while (++i < bufsiz / 64)
		sha256_inprocess(buf + i * 16);
	sha256_postprocess(input);
}

void	sha256_str(char *msg)
{
	uint64_t	sublen;
	uint64_t	bitlen;
	char		*input;

	sublen = ft_strlen(msg);
	bitlen = sublen * 8;
	input = ft_strcompose(3, "\"", msg, "\"");
	sha256_process((uint32_t *)msg, sublen, bitlen, input);
	free(input);
}
