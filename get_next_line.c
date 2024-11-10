/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:48 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/09 19:47:00 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line[FD_MAX];
	//size_t		read_size;

	line[fd] = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = manage_buffer(fd, line);
	printf("The value is returned to get_next_line");
	printf("line[fd] = %s\n", line[fd]);
	if (line[fd] == NULL)
		return (NULL);
	printf("line[%d]: %s\n", fd, line[fd]);
	return ("Testing");
}

char	*manage_buffer(int fd, char **line)
{
	char	*buffer;
	char	temp[BUFFER_SIZE + 1];
	ssize_t	read_size;
	size_t	iter;

	iter = 0;
	while ((read_size = read(fd, temp, BUFFER_SIZE + 1)) > 0)
	{
		temp[read_size] = '\0';
		if(!line[fd])
			line[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		buffer = ft_strjoin(line[fd], temp);
		if (!buffer)
			return (NULL);
		line[fd] = buffer;
		while (temp[iter] != '\0')
		{
			if (temp[iter] == '\n')
				break;
			iter++;
		}
		printf("line[fd] = %s\n", line[fd]);
	}
	return (line[fd]);
}

char	*get_line(int fd, char **line)
{
	printf("Inside get_line %d, %p\n", fd, line);
	return ("");
}