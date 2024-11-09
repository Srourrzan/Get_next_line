/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:07 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/07 19:22:01 by gitpod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//manage_buffer
char    *manage_buffer(int fd, char **line, int read_size)
{
    char    *buffer;
    char    *temp;

    temp = line[fd];
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if(buffer == NULL)
    {
        free(line[fd]);
        return (NULL);
    }
    read_size = read(fd, buffer, BUFFER_SIZE);
}

//get_line
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!joined_str)
		return (NULL);
	ft_strlcpy(joined_str, s1, len_s1 + 1);
	ft_strlcat(joined_str, s2, len_s1 + len_s2 + 1);
	return (joined_str);
}

char	*ft_strdup(const char *s1)
{
	char	*dup_str;
	size_t	len;
	int		iter;

	iter = 0;
	len = ft_strlen(s1);
	dup_str = (char *)malloc((len + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	while (s1[iter] != '\0')
	{
		dup_str[iter] = s1[iter];
		iter++;
	}
	dup_str[iter] = '\0';
	return (dup_str);
}