/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:04:19 by zwang             #+#    #+#             */
/*   Updated: 2018/11/08 21:11:11 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	h0 = 0x6a09e667;
uint32_t	h1 = 0xbb67ae85;
uint32_t	h2 = 0x3c6ef372;
uint32_t	h3 = 0xa54ff53a;
uint32_t	h4 = 0x510e527f;
uint32_t	h5 = 0x9b05688c;
uint32_t	h6 = 0x1f83d9ab;
uint32_t	h7 = 0x5be0cd19;

uint32_t	k[64] = \
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void		reverse_4_bytes(uint32_t *set)
{
	uint32_t	p1;
	uint32_t	p2;
	uint32_t	p3;
	uint32_t	p4;

	p1 = *set << 24;
	p2 = ((*set >> 8) << 24) >> 8;
	p3 = ((*set << 8) >> 24) << 8;
	p4 = *set >> 24;
	*set = p1 | p2 | p3 | p4;
}

uint32_t	*sha256_preprocess(uint32_t *stream, uint64_t sublen, uint64_t bitlen,
						uint64_t bufsiz)
{
	uint32_t	*buf;
	uint64_t	i;
	uint64_t	j;
	uint8_t		*p;
	uint8_t		*q;

	if (!(buf = (uint32_t *)malloc(bufsiz)))
		return (NULL);
	p = (uint8_t *)buf;
	q = (uint8_t *)stream;
	i = -1;
	while (++i < sublen)
		ft_memcpy(&p[i], &q[i], 1);
	p[sublen] = 0x80;
	i = 1;
	while (sublen + i < bufsiz - 8)
		p[sublen + i++] = 0x00;
	j = -1;
	while (++j < sublen / 4 + 1)
		reverse_4_bytes(&buf[j]);
	ft_memcpy(&p[sublen + i], &bitlen, 8);
	ft_memswap(&p[sublen + i], &p[sublen + i] + 4, 4);
	for (int k = 0; k < 16; k++)
		ft_putbits(&buf[k], 32);
	return (buf);
}

void		sha256_inprocess(uint32_t *chunk)
{
	uint32_t	w[64];
	uint32_t	s0, s1, maj, ch, t1, t2;
	uint32_t	a, b, c, d, e, f, g, h;
	uint32_t	i;
	uint32_t	tmp[3];
	
	ft_memcpy(w, chunk, 64);
	i = 15;
	while (++i < 64)
	{
		s0 = ROTRIGHT(w[i - 15], 7) ^ ROTRIGHT(w[i - 15], 18) ^
				ROTRIGHT(w[i - 15], 3);
		s1 = ROTRIGHT(w[i - 2], 17) ^ ROTRIGHT(w[i - 2], 19) ^
				ROTRIGHT(w[i - 2], 10);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
	}
	a = h0;
	b = h1;
	c = h2;
	d = h3;
	e = h4;
	f = h5;
	g = h6;
	h = h7;
	i = -1;
	while (++i < 64)
	{
		s0 = ROTRIGHT(a, 2) ^ ROTRIGHT(a, 13) ^ ROTRIGHT(a, 22);
		maj = (a & b) ^ (a & c) ^ (b & c);
		t2 = s0 + maj;
		s1 = ROTRIGHT(e, 6) ^ ROTRIGHT(e, 11) ^ ROTRIGHT(e, 25);
		ch = (e & f) ^ (~e & g);
		t1 = h + s1 + ch + k[i] + w[i];
		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}
	h0 += a;
	h1 += b;
	h2 += c;
	h3 += d;
	h4 += e;
	h5 += f;
	h6 += g;
	h7 += h;	
}

void		sha256_postprocess(char *input)
{
	ft_printf("SHA256 (%s) = ", input);
	ft_printf("%08x%08x%08x%08x%08x%08x%08x%08x\n",
				h0, h1, h2, h3, h4, h5, h6, h7);
}
