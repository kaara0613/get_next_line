/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:57:05 by kaara             #+#    #+#             */
/*   Updated: 2024/12/05 14:28:30 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static bool	gnl_realloc(char **buffer, const char *read_buffer);
static bool	save_buffer(int fd, char **buffer);
static bool	read_fd(int fd, char **buffer, char *read_buffer);
static char	*make_result(const char	*buffer, size_t	start);

char	*get_next_line(int fd)
{
	char			*result_buffer;
	static size_t	buffer_start = 0;
	static char		*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer != NULL)
	{
		while (buffer[buffer_start] != '\n' && buffer[buffer_start] != '\0')
			buffer_start++;
		if (buffer[buffer_start] == '\n')
			buffer_start++;
	}
	if (!save_buffer(fd, &buffer))
		return (free(buffer), NULL);
	result_buffer = make_result(buffer, buffer_start);
	if (!result_buffer)
		return (free(buffer), NULL);
	return (result_buffer);
}

static bool	gnl_realloc(char **buffer, const char *read_buffer)
{
	size_t	buffer_len;
	size_t	mix_len;
	char	*new_buffer;

	buffer_len = 0;
	if (buffer)
		buffer_len = ft_strlen(*buffer);
	mix_len = buffer_len + ft_strlen(read_buffer);
	new_buffer = (char *)malloc(mix_len + 1);
	if (!new_buffer)
		return (false);
	if (buffer)
	{
		ft_strlcpy(new_buffer, *buffer, buffer_len + 1);
		free(*buffer);
	}
	ft_strlcpy(new_buffer + buffer_len,
		read_buffer, mix_len - buffer_len + 1);
	*buffer = new_buffer;
	return (true);
}

static bool	save_buffer(int fd, char **buffer)
{
	char	*read_buffer;

	read_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	if (!read_fd(fd, buffer, read_buffer))
		return (free(read_buffer), false);
	else
		return (free(read_buffer), true);
}

bool	read_fd(int fd, char **buffer, char *read_buffer)
{
	ssize_t	len;

	while (1)
	{
		ft_bzero(read_buffer, BUFFER_SIZE + 1);
		len = read(fd, read_buffer, BUFFER_SIZE);
		if (len < 0)
			return (false);
		if (len == 0 && read_buffer[0] == '\0')
			break ;
		if (!gnl_realloc(buffer, read_buffer))
			return (false);
		if (ft_strrchr(read_buffer, '\n'))
			break ;
		len = 0;
		while (len <= BUFFER_SIZE)
			read_buffer[len++] = '\0';
	}
	return (true);
}

static char	*make_result(const char	*buffer, size_t start)
{
	size_t	len;
	char	*result;

	if (!buffer || buffer[start] == '\0')
		return (NULL);
	len = start;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	len -= start;
	result = ft_substr(buffer, start, len + 1);
	if (!result)
		return (NULL);
	return (result);
}
