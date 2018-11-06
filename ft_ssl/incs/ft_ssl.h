/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:27:51 by zwang             #+#    #+#             */
/*   Updated: 2018/11/05 19:02:16 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include "libft.h"

# define IS_MD5(s)		(ft_strequ(s, "md5") || ft_strequ(s, "MD5"))

# define ROTLEFT(a,b)	((a << b) | (a >> (32 - b)))

typedef struct	s_var
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
}				t_var;

uint32_t	*preprocess(uint32_t *stream, uint64_t sublen, uint64_t bitlen,
						uint64_t bufsiz);
void		inprocess(uint32_t *buf);
void		postprocess(char *input);

void	md5_str(char *msg);
void	md5_file(char *name);

#endif
