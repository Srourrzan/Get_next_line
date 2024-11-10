/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:48 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/10 19:12:38 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line[FD_MAX];
	char		*p_line;

	line[fd] = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = manage_buffer(fd, line);
	if (line[fd] == NULL)
		return (NULL);
	p_line = get_line(line[fd]);
	return (p_line);
}

char	*manage_buffer(int fd, char **line)
{
	char	temp[BUFFER_SIZE + 1];
	ssize_t	read_size;

	while ((read_size = read(fd, temp, BUFFER_SIZE + 1)) > 0)
	{
		temp[read_size] = '\0';
		if(!line[fd])
			line[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		line[fd] = ft_strjoin(line[fd], temp);
		if (!line[fd])
			return (NULL);
		if (ft_strchr(line[fd], '\n'))
			break;
	}
	return (line[fd]);
}

char	*get_line(char *line)
{
	//char	*buffer = "Razan\nSrour";
	char	*newline_pos;
	//size_t	len;
	
	printf("passed line: %s\n", line);
	newline_pos = ft_strchr(line, '\n');
	printf("newline: %s\n", newline_pos);
	return (newline_pos);
}

char	*ft_strchr(const char *s, int c)
{
	while(*s != '\0' && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
