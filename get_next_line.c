/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:48 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/09 10:46:35 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line[FD_MAX];
	int			read_size;

	read_size = BUFFER_SIZE;
	line[fd] = NULL;
	while (read_size > 0)
	{
		manage_buffer(fd, line, read_size);
	}
	get_line(fd, line);
}

char	*manage_buffer(int fd, char **line, int read_size)
{
	char	*buffer;
	char	*temp;

	temp = line[fd];
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		free(line[fd]);
		return (NULL);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	line[fd] = ft_strjoin(temp, buffer);
	free(buffer);
	free(temp);
}
