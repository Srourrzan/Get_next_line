/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:48 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/10 21:15:43 by rsrour           ###   ########.fr       */
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
	char	*temp;
	ssize_t	read_size;

	printf("allocaring temp\n");
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	read_size = 1;
	while (!ft_find_newline(line[fd]) && read_size > 0)
	{
		printf("reading file...\n");
		read_size = read(fd, temp, BUFFER_SIZE);
		if(read_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_size] = '\0';
		line[fd] = ft_strjoin(line[fd], temp);
		printf("newline? %s\n", ft_find_newline(line[fd]));
	}
	printf("line[fd]: %s\n", line[fd]);
	free(temp);
	return (line[fd]);
}

char	*get_line(char *line)
{
	//char	*buffer = "Razan\nSrour";
	char	*newline_pos;
	//size_t	len;
	
	printf("passed line: %s\n", line);
	newline_pos = ft_find_newline(line);
	printf("newline: %s\n", newline_pos);
	return (newline_pos);
}

char	*ft_find_newline(const char *s)
{
	int		i;

	i = 0;
	if(!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\\')
		i++;
	if (s[i] == '\\' && s[i + 1] == 'n')
		return((char *)&s[i]);
	return (NULL);
}