/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:57:05 by kaara             #+#    #+#             */
/*   Updated: 2024/08/31 11:39:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_realloc(char *buffer, const char *read_buffer);
static int	save_buffer(int fd, char **buffer);
static char	*make_result(const char	*buffer, size_t	start);

char	*get_next_line(int fd)
{
	int				i;
	char			*result_buffer;
	static size_t	buffer_start = 0;
	static char		*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer && (buffer[buffer_start] != '\n'
			&& buffer[buffer_start] != '\0'))
		buffer_start++;
	if (buffer && buffer[buffer_start] == '\n')
		buffer_start++;
	i = save_buffer(fd, &buffer);
	if (i <= 0)
		return (free(buffer), buffer = NULL, buffer_start = 0, NULL);
	result_buffer = make_result(buffer, buffer_start);
	if (!result_buffer)
		return (free(buffer), buffer = NULL, buffer_start = 0, NULL);
	return (result_buffer);
}

static char	*gnl_realloc(char *buffer, const char *read_buffer)
{
	size_t	buffer_len;
	size_t	mix_len;
	char	*new_buffer;

	buffer_len = 0;
	if (buffer)
		buffer_len = ft_strlen(buffer);
	mix_len = buffer_len + ft_strlen(read_buffer);
	new_buffer = (char *)malloc(mix_len + 1);
	if (!new_buffer)
		return (NULL);
	if (buffer)
	{
		ft_strlcpy(new_buffer, buffer, buffer_len + 1);
		free(buffer);
	}
	ft_strlcpy(new_buffer + buffer_len,
		read_buffer, mix_len - buffer_len + 1);
	return (new_buffer);
}

static int	save_buffer(int fd, char **buffer)
{
	ssize_t	len;
	char	read_buffer[BUFFER_SIZE + 1];

	while (1)
	{
		ft_bzero(read_buffer, BUFFER_SIZE);
		len = read(fd, read_buffer, BUFFER_SIZE);
		if (len < 0)
			return (ft_bzero(read_buffer, BUFFER_SIZE), -1);
		if (len == 0 && read_buffer[0] == '\0')
			return (ft_bzero(read_buffer, BUFFER_SIZE), 2);
		*buffer = gnl_realloc(*buffer, read_buffer);
		if (!*buffer)
			return (ft_bzero(read_buffer, BUFFER_SIZE), 0);
		if (ft_strrchr(read_buffer, '\n'))
			break ;
		len = 0;
		while (len <= BUFFER_SIZE)
			read_buffer[len++] = '\0';
	}
	ft_bzero(read_buffer, BUFFER_SIZE);
	return (1);
}

static char	*make_result(const char	*buffer, size_t	start)
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
