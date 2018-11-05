/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:41:04 by zwang             #+#    #+#             */
/*   Updated: 2018/11/05 15:24:09 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	md5_str(char *msg)
{
	uint64_t	len;
	uint64_t	bufsiz;
	uint32_t	*buf;
	uint64_t	i;

	len = ft_strlen(msg);
	bufsiz = len + 1;
	while (bufsiz % 64 != 0)
		bufsiz += 1;
	if (!(buf = preprocess(msg, len, bufsiz)))
		ft_printf("malloc error\n");
	i = -1;
	while (++i < bufsiz / 64)
		inprocess(buf + i * 16);
	postprocess();
}

void	md5_file(char *name)
{
	uint32_t	buf[16];
	int			fd;

	fd = open(name, O_RDONLY);
	ft_bzero(buf, 64);
	while (read(fd, buf, 64) == 64)
	{
		inprocess(buf);
		ft_bzero(buf, 64);
	}
	md5_str((char *)buf);
}
