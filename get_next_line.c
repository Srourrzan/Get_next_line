/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:48 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/11 12:45:48 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*p_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = manage_buffer(fd, line);
	if (line == NULL)
		return (NULL);
	p_line = ft_get_line(line);
	line = get_rest_line(line);
	return (p_line);
}

char	*manage_buffer(int fd, char *line)
{
	char	*temp;
	ssize_t	read_size;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	read_size = 1;
	while (!ft_find_newline(line) && read_size > 0)
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if(read_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[read_size] = '\0';
		line = ft_strjoin(line, temp);
	}
	free(temp);
	return (line);
}

char	*ft_get_line(char *line)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = 0;
	if(!line[len])
		return (NULL);
	while (line[len] && line[len] != '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return(NULL);
	while (line[i] && i < len)
	{
		str[i] = line[i];
		i++;
	}
	if (line[len] == '\n')
		str[i++] = line[len];
	str[i] = '\0';
	return(str);
}
