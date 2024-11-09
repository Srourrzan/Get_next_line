/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:48 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/09 12:59:32 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line[FD_MAX];
	size_t			read_size;

	line[fd] = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE > 0)
	{
		read_size = manage_buffer(fd, line, size_t);
		printf("line[%d]: %s\n", fd, line[fd]);
		printf("read size = %ld\n", read_size);
	}
	//get_line(fd, line);
	return ("Testing");
}

size_t    manage_buffer(int fd, char **line, size_t read_size)
{
	char	*buffer;
	char	*temp;

	temp = line[fd];
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
	{
		free(line[fd]);
		return (0);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	line[fd] = ft_strjoin(temp, buffer);
	free(buffer);
	free(temp);
	return(read_size);
}

char    *get_line(int fd, char **line)
{
    printf("Inside get_line %d, %p\n", fd, line);
    return ("");
}