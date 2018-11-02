/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 10:12:18 by zwang             #+#    #+#             */
/*   Updated: 2018/10/29 19:32:41 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* MD5 context. */
typedef struct {
	UINT4 			state[4];	/* state (ABCD) */
	UINT4 			count[2];	/* number of bits, modulo 2^64 (lsb first) */
	unsigned char	buffer[64];		/* input buffer */
} MD5_CTX;

void MD5Init PROTO_LIST ((MD5_CTX *));
void MD5Update PROTO_LIST
  ((MD5_CTX *, unsigned char *, unsigned int));
void MD5Final PROTO_LIST ((unsigned char [16], MD5_CTX *));
