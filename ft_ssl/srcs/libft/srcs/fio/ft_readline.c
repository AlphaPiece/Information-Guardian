/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:14:37 by zwang             #+#    #+#             */
/*   Updated: 2018/09/20 11:34:28 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_readline(int fd, char **line)
{
	int		flag;
	char	*ptr;

	if ((flag = ft_nextline(fd, line)) > 0)
	{
		ptr = *line;
		*line = ft_strjoin(*line, "\n");
		free(ptr);
		return (1);
	}
	else if (flag < 0)
		return (-1);
	else
		return (0);
}
