/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 11:27:51 by zwang             #+#    #+#             */
/*   Updated: 2018/10/16 11:30:33 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

# define ROTLEFT(a,b) ((a << b) | (a >> (32-b)))

# define F(x,y,z) ((x & y) | (~x & z))
# define G(x,y,z) ((x & z) | (y & ~z))
# define H(x,y,z) (x ^ y ^ z)
# define I(x,y,z) (y ^ (x | ~z))

# define FF(a,b,c,d,m,s,t) {a += F(b,c,d) + m + t; \
							a = b + ROTLEFT(a,s);}
# define GG(a,b,c,d,m,s,t) {a += G(b,c,d) + m + t; \
							a = b + ROTLEFT(a,s);}
# define HH(a,b,c,d,m,s,t) {a += H(b,c,d) + m + t; \
							a = b + ROTLEFT(a,s);}
# define II(a,b,c,d,m,s,t) {a += I(b,c,d) + m + t; \
                            a = b + ROTLEFT(a,s);}

#endif
