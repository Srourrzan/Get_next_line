/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:49:43 by gitpod            #+#    #+#             */
/*   Updated: 2024/11/07 19:07:15 by gitpod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#ifndef FD_MAX
# define FD_MAX 1042
#endif

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_next_line(int fd);

#endif