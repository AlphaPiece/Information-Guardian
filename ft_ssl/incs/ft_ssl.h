/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:27:51 by zwang             #+#    #+#             */
/*   Updated: 2019/04/06 21:28:03 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include "libft.h"

# define IS_MD5(s)		(ft_strequ(s, "md5") || ft_strequ(s, "MD5"))
# define IS_SHA256(s)	(ft_strequ(s, "sha256") || ft_strequ(s, "SHA256"))

# define ROTLEFT(a, b)	((a << b) | (a >> (32 - b)))
# define ROTRIGHT(a, b)	((a >> b) | (a << (32 - b)))

typedef struct	s_op
{
	t_bool		s;
	t_bool		p;
	t_bool		q;
	t_bool		r;
}				t_op;

typedef struct	s_var
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
}				t_var;

/*
** MD5
*/

uint32_t		*md5_preprocess(uint32_t *stream, uint64_t sublen,
								uint64_t bitlen, uint64_t bufsiz);
void			md5_inprocess(uint32_t *chunk);
void			md5_passcode(void);
void			md5_postprocess(char *input, t_op *op);

void			md5_process(uint32_t *stream, uint64_t sublen, uint64_t bitlen);
void			md5_str(char *msg, t_op *op);
void			md5_file(char *name, t_op *op);
void			md5_reset(void);

#endif
