/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:16:00 by zwang             #+#    #+#             */
/*   Updated: 2018/11/09 11:50:39 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int argc, char **argv)
{
	if (argc >= 3)
	{
		if (IS_MD5(argv[1]) && ft_strequ(argv[2], "-s"))
			md5_str(argv[3]);
		else if (IS_MD5(argv[1]))
			md5_file(argv[2]);
		else if (IS_SHA256(argv[1]) && ft_strequ(argv[2], "-s"))
			sha256_str(argv[3]);
		else if (IS_SHA256(argv[1]))
			sha256_file(argv[2]);
	}
	return (0);
}
