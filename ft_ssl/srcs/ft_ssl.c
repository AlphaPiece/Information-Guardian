/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:16:00 by zwang             #+#    #+#             */
/*   Updated: 2018/11/05 15:20:22 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int argc, char **argv)
{
	if (argc >= 3)
	{
		if (ft_strequ(argv[1], "md5") && ft_strequ(argv[2], "-s"))
			md5_str(argv[3]);
		else if (ft_strequ(argv[1], "md5"))
			md5_file(argv[2]);
	}
	return (0);
}
