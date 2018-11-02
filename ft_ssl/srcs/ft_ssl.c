/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 13:38:31 by zwang             #+#    #+#             */
/*   Updated: 2018/11/02 15:50:35 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	s[64] = \
{
	7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
	5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
	4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
	6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
};

uint32_t	K[64] = \
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

uint32_t	a0 = 0x67452301;
uint32_t	b0 = 0xefcdab89;
uint32_t	c0 = 0x98badcfe;
uint32_t	d0 = 0x10325476;

uint32_t	rol(uint32_t v, uint16_t amt)
{
    uint32_t	msk1 = (1 << amt) - 1;
    return (((v >> (32 - amt)) & msk1) | ((v << amt) & ~msk1));
}

uint32_t	*preprocess(char *msg, uint64_t len, uint64_t bufsiz)
{
	uint32_t	*buf;
	uint64_t	i;
	uint64_t	j;
	uint8_t		*p;

	if (!(buf = (uint32_t *)malloc(bufsiz + 1)))
		return (NULL);
	ft_memcpy(buf, msg, len);
	p = (uint8_t *)buf;
	p[len] = 0x80;
	i = 1;
	while (len + i < bufsiz - 8)
		p[len + i++] = 0x00;
	j = len * 8;
	ft_memcpy(&p[len + i], &j, 8);
	j = 0;
	return (buf);
}

void		inprocess(uint32_t *buf, uint64_t bufsiz)
{
	uint32_t	a = a0, b = b0, c = c0, d = d0, F, g, i, j;

	i = -1;
	while (++i < bufsiz / 4)
	{
		j = -1;
		while (++j < 64)
		{
			if (i <= 15)
			{
				F = (b & c) | (~b & d);
				g = i;
			}
			else if (16 <= i && i <= 31)
			{
				F = (d & b) | (~d & c);
				g = (5 * i + 1) % 16;
			}
			else if (32 <= i && i <= 47)
			{
				F = b ^ c ^ d;
				g = (3 * i + 5) % 16;
			}
			else if (48 <= i && i <= 63)
			{
				F = c ^ (b | ~d);
				g = (7 * i) % 16;
			}
			F = F + a + K[i] + buf[g];
			a = d;
			d = c;
			c = b;
			b = b + rol(F, s[i]);
		}
		a0 += a;
		b0 += b;
		c0 += c;
		d0 += d;
	}
}

void		postprocess(void)
{
	ft_printf("%08x%08x%08x%08x\n", a0, b0, c0, d0);
}

void		ft_ssl(char *msg)
{
	uint64_t	len;
	uint64_t	bufsiz;
	uint32_t	*buf;

	len = ft_strlen(msg);
	bufsiz = len + 1;
	while (bufsiz % 64 != 0)
		bufsiz += 1;
	if (!(buf = preprocess(msg, len, bufsiz)))
		ft_printf("malloc error\n");
	inprocess(buf, bufsiz);
	postprocess();
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		ft_ssl(argv[1]);
	return (0);
}
