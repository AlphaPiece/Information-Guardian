/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:53:22 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 09:50:59 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nextline.h"

/*
** Function add_or_extract creates a linked list of files so as to let
** ft_nextline be able to handle multiple files at the same time.
**
** Each file contains a buffer in which saves the characters after the first
** newline character in the BUFF_SIZE number of characters that ft_nextline
** read last time.
*/

static t_file	*add_or_extract(t_file **file_list, const int fd)
{
	t_file	*file;

	file = *file_list;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	if (!(file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	file->fd = fd;
	file->save = NULL;
	file->next = *file_list;
	*file_list = file;
	return (file);
}

/*
** Function find_and_store finds the next line. If there a newline character in
** the buffer, it gets from it. Otherwise it read again from the file.
*/

static char		*find_and_store(t_file *file, char buffer[BUFF_SIZE + 1])
{
	char	*tmp;
	char	*sub;
	char	*nlc;
	char	*str;
	size_t	size;

	str = ft_strnew(0);
	while (!(nlc = ft_strchr(buffer, '\n')))
	{
		MALLOC_FREE(tmp, str, ft_strjoin(str, buffer));
		if (!(size = read(file->fd, buffer, BUFF_SIZE)))
		{
			ft_strdel(&(file->save));
			return (str);
		}
		buffer[size] = '\0';
	}
	sub = ft_strsub(buffer, 0, NL_INDEX);
	MALLOC_FREE(tmp, str, ft_strjoin(str, sub));
	free(sub);
	MALLOC_FREE(tmp, file->save,
			ft_strsub(buffer, NL_INDEX + 1, BUFF_SIZE - NL_INDEX));
	return (str);
}

/*
** Function ft_nextline first checks if the file it's going to read is already
** in the linked list of files. And then it checks if there's something in the
** file buffer (file->save); if not, it reads.
**
** RETURN -1: When the program fails to open the file, or when there's nothing
** in line, or when the function read returns a error value (negative number),
** or when the BUFF_SIZE is defined as a number less than 1.
** RETURN 0: When it finishes reading the file, (there's nothing in the file
** to be read).
** RETURN 1: When it is not any of the situations above and get_next_line
** successfully finds a new line and stores it in **line.
*/

int				ft_nextline(const int fd, char **line)
{
	static t_file	*file_list;
	char			buffer[BUFF_SIZE + 1];
	t_file			*file;
	size_t			size;

	if (fd < 0 || !line || read(fd, buffer, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	file = add_or_extract(&file_list, fd);
	if (file->save && ft_strlen(file->save))
		ft_strcpy(buffer, file->save);
	else
	{
		if (!(size = read(fd, buffer, BUFF_SIZE)))
		{
			ft_strdel(&(file->save));
			return (0);
		}
		buffer[size] = '\0';
	}
	*line = find_and_store(file, buffer);
	return (1);
}
