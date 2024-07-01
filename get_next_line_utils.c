/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:01:02 by kaara             #+#    #+#             */
/*   Updated: 2024/07/01 13:46:18 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dstsize -= 1;
	while (dstsize-- && *src != '\0')
		*dst++ = *src++;
	*dst++ = '\0';
	return (src_len);
}

int	check_line(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

char	*find_newline_char(char *read_buffer)
{
	while (*read_buffer != '\n' && *read_buffer)
		read_buffer++;
	if (*read_buffer == '\n')
		*(read_buffer + 1) = '\0';
	return (read_buffer);
}

char	*gnl_realloc(char *buffer, const char *read_buffer)
{
	size_t	buffer_len;
	size_t	mix_len;
	char	*temp_buffer;

	buffer_len = 0;
	if (buffer)
		ft_strlen(buffer);
	mix_len = buffer_len + ft_strlen(read_buffer);
	temp_buffer = (char *)malloc(mix_len + 1);
	if (!temp_buffer)
		return (NULL);
	if (buffer)
	{
		ft_strlcpy(temp_buffer, buffer, buffer_len + 1);
		free(buffer);
	}
	ft_strlcpy(temp_buffer + buffer_len, read_buffer, ft_strlen(read_buffer) + 1);
	return (temp_buffer);
}