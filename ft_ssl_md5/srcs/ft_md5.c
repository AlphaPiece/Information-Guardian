/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:30:48 by zwang             #+#    #+#             */
/*   Updated: 2018/10/19 15:17:03 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

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

uint8_t	*preprocess(uint8_t *msg, uint64_t len, uint64_t bufsiz)
{
	uint8_t		*buf;
	uint64_t	i;
	
	if (!(buf = (uint8_t *)malloc(sizeof(char) * (bufsiz + 1))))
		return(NULL);
	ft_memcpy(buf, msg, len);
	buf[len] = 128;
	i = 1;
	while (len + i < bufsiz - 2)
		buf[len + i++] = 0;
	buf[len + i] = 255;
	buf[len + i] &= (len >> 8) << 8;
	i++;
	buf[len + i] = 255;
	buf[len + i] &= len;
	for (int i = 0; i < bufsiz; i++)
		ft_putbits(buf[i], 8);
	return (buf);
}

void	inprocess(uint8_t *msg)
{
	uint32_t	i, a, b, c, d, F, g;

	i = -1;
	while (++i < 64)
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
        F = F + a + K[i] + msg[g];
        a = d;
        d = c;
        c = b;
        b = b + ROTLEFT(F, s[i]);
    }
    a0 += a;
    b0 += b;
    c0 += c;
    d0 += d;
}

void    ft_md5(uint8_t *msg)
{
    uint64_t    len;
    uint64_t    bufsiz;
    uint8_t     *buf;
    uint8_t     i;
    uint8_t		*digest[4];

    len = ft_strlen((char *)msg);
    bufsiz = len;
    while (bufsiz % 64 != 0)
        bufsiz += 1;
    if (!(buf = preprocess(msg, len, bufsiz)))
		ft_printf("malloc error\n");
    i = 0;
    while (i / bufsiz == 0)
    {
        inprocess(msg);
        i += 64;
    }
	digest[0] = (uint8_t *)ft_untoa_base(a0, 16, 'a');
	digest[1] = (uint8_t *)ft_untoa_base(b0, 16, 'a');
	digest[2] = (uint8_t *)ft_untoa_base(c0, 16, 'a');
	digest[3] = (uint8_t *)ft_untoa_base(d0, 16, 'a');
	i = -1;
	while (++i < 4)
		ft_printf("%s", (char *)digest[i]);
	ft_printf("\n");
	i = -1;
	while (++i < 4)
		free(digest[i]);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_md5((uint8_t *)argv[1]);
	}
	return (0);
}
