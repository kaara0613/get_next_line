/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:03:48 by kaara             #+#    #+#             */
/*   Updated: 2024/07/01 19:20:31 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);

int		check_line(const char *line);
char	*find_newline_char(char *read_buffer);
char	*gnl_realloc(char *buffer, const char *read_buffer);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif