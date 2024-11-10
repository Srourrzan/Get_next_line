/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:43 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/10 21:48:03 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef FD_MAX
#  define FD_MAX 1042
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

char	*get_next_line(int fd);
char	*manage_buffer(int fd, char *line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*get_line(char *line);
char	*ft_find_newline(const char *s);

#endif