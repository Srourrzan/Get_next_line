/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:50:07 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/09 10:45:49 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlen(char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
		iter++;
	return (iter);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		iter;
	size_t		length;
	const char	*buffer;

	iter = 0;
	buffer = src;
	length = ft_strlen(buffer);
	if (!src)
		return (0);
	if (size == 0)
		return (length);
	while (iter < length && iter < (size - 1))
	{
		dst[iter] = buffer[iter];
		iter++;
	}
	dst[iter] = '\0';
	return (length);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	iter;

	destlen = ft_strlen(dst);
	if (size <= destlen)
		return (size + ft_strlen(src));
	iter = 0;
	while (src[iter] != '\0' && destlen + iter < size - 1)
	{
		dst[destlen + iter] = src[iter];
		iter++;
	}
	dst[destlen + iter] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[iter]));
}
