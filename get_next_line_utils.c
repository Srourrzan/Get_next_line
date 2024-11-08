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