/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:06:54 by zwang             #+#    #+#             */
/*   Updated: 2018/09/20 17:15:20 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_read(char *file_name, char **content)
{
	int		fd;
	char	*line;
	char	*ptr;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	*content = "";
	while (ft_readline(fd, &line) > 0)
	{
		ptr = *content;
		*content = ft_strjoin(*content, line);
		if (*ptr)
			free(ptr);
		free(line);
	}
	if (close(fd) < 0)
		return (-1);
	return (ft_strlen(*content));
}
