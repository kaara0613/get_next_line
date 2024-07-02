/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:57:05 by kaara             #+#    #+#             */
/*   Updated: 2024/07/02 18:52:18 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_line(const char *line);
static char	*find_newline_char(char *read_buffer);
static char	*gnl_realloc(char *buffer, const char *read_buffer);

char	*get_next_line(int fd)
{
	ssize_t		len;
	size_t		total_len;
	char		read_buffer[BUFFER_SIZE + 1];
	char		*result_buffer;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	total_len = 0;
	if (buffer)
		total_len = ft_strlen(buffer);
	while (!buffer || !check_line(buffer + total_len))
	{
		len = read(fd, read_buffer, BUFFER_SIZE);
		if (len < 0 || (len == 0 && !buffer))
			return (NULL);
		if (len == 0)
			break ;
		*(read_buffer + len) = '\0';
		find_newline_char(read_buffer);
		buffer = gnl_realloc(buffer, read_buffer);
		*read_buffer = '\0';
	}
	result_buffer = ft_strdup(buffer + total_len);
	if (!result_buffer)
		return (NULL);
	if (len == 0)
		return (free(buffer), result_buffer);
	return (result_buffer);
}

static int	check_line(const char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

static char	*find_newline_char(char *read_buffer)
{
	while (*read_buffer && *read_buffer != '\n')
		read_buffer++;
	if (*read_buffer == '\n')
		*(read_buffer + 1) = '\0';
	return (read_buffer);
}

static char	*gnl_realloc(char *buffer, const char *read_buffer)
{
	size_t	buffer_len;
	size_t	mix_len;
	char	*temp_buffer;

	buffer_len = 0;
	if (buffer)
		buffer_len = ft_strlen(buffer);
	mix_len = buffer_len + ft_strlen(read_buffer);
	temp_buffer = (char *)malloc(mix_len + 1);
	if (!temp_buffer)
		return (NULL);
	if (buffer)
	{
		ft_strlcpy(temp_buffer, buffer, buffer_len + 1);
		free (buffer);
	}
	ft_strlcpy(temp_buffer + buffer_len,
		read_buffer, ft_strlen(read_buffer) + 1);
	return (temp_buffer);
}
