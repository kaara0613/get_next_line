/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:01:04 by kaara             #+#    #+#             */
/*   Updated: 2024/07/01 22:38:15 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    ssize_t        len;
    size_t        total_len;
    char        read_buffer[BUFFER_SIZE + 1];
    static char    *buffer = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    total_len = 0;
    if (buffer)
        total_len = ft_strlen(buffer);
    while (!buffer || !check_line(buffer + total_len))
    {
        len = read(fd, read_buffer, BUFFER_SIZE);
        if (len < 0)
            return (free(buffer), NULL);
        if (len == 0)
            return (buffer + total_len);
        *(read_buffer + len) = '\0';
        // if (buffer)
        //     len += ft_strlen(buffer);
        find_newline_char(read_buffer);
		buffer = gnl_realloc(buffer, read_buffer);
        *read_buffer = '\0';
    }
    return (buffer + total_len);
}
