/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:57:05 by kaara             #+#    #+#             */
/*   Updated: 2024/08/21 14:39:49 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gnlはreadが0を2回返した時に終了する。
//bufferがNULLの時を終了条件にすると、最初のNULLでgnlが終了する。

#include "get_next_line.h"

// static char	*find_newline_char(char *read_buffer);
static char	*gnl_realloc(char *buffer, const char *read_buffer);
static int	save_buffer(int	fd, char	*buffer);
static char	*make_result(const char	*buffer, unsigned int	start);

// char	*get_next_line(int fd)
// {
// 	ssize_t		len;
// 	size_t		total_len;
// 	char		read_buffer[BUFFER_SIZE + 1];
// 	char		*result_buffer;
// 	static char	*buffer = NULL;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	total_len = 0;
// 	if (buffer)
// 		total_len = ft_strlen(buffer);
// 	while (!buffer || !ft_strchr(buffer + total_len, '\n'))
// 	{// read_buffferをbufferに貯めていく
// 		len = read(fd, read_buffer, BUFFER_SIZE);
// 		if (len == 0 && buffer)
// 			break ;//readが1回目の0を返した時。
// 		if (len < 0 || (len == 0 && !buffer))
// 			return (NULL);//read失敗とreadが2回目の0を返した時。
// 		*(read_buffer + len) = '\0';
// 		find_newline_char(read_buffer);
// 		buffer = gnl_realloc(buffer, read_buffer);
// 		if (!buffer)
// 			return (NULL);
// 		*read_buffer = '\0';
// 	}
// 	if (!buffer)
// 		return (NULL);
// 	if (buffer[total_len] == '\0')
// 		return (free(buffer), buffer = NULL, NULL);
//     result_buffer = ft_strdup(buffer + total_len);
//     if (!result_buffer)
// 		return (NULL);
//     return (result_buffer);
// }

// static char	*find_newline_char(char *read_buffer)
// {
// 	while (*read_buffer && *read_buffer != '\n')
// 		read_buffer++;
// 	if (*read_buffer == '\n')
// 		*(read_buffer + 1) = '\0';
// 	return (read_buffer);
// }

char	*get_next_line(int fd)
{
	int				i;
	ssize_t			buffer_start;
	char			*result_buffer;
	static char		*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer_start = ft_strlen(buffer);
	i = save_buffer(fd, buffer);
	if (i == 0)
		return (NULL);
	result_buffer = make_result(buffer, (unsigned int)buffer_start);
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
		free (buffer);
	}
	ft_strlcpy(new_buffer + buffer_len,
		read_buffer, ft_strlen(read_buffer) + 1);
	return (new_buffer);
}

static int	save_buffer(int	fd, char	*buffer)//0から'\n'が見つかるまでbufferに貯める
{
	ssize_t		len;
	char		read_buffer[BUFFER_SIZE + 1];

	while (1)
	{
		len = read(fd, read_buffer, BUFFER_SIZE);
		*read_buffer = '\0';
		if (len < 0 || (len == 0 && read_buffer[0] == '\0'))
			return (read_buffer[0] = '\0', 0);//read失敗もしくはの時。
		buffer = gnl_realloc(buffer, read_buffer);
		if (!buffer) //allocation失敗
			return (0);
		if (ft_strrchr(read_buffer, '\n'))//read_buferに\nが見つかれば初期化してbreak。
			break ;
	}
	return (read_buffer[0] = '\0', 1);
}

static char	*make_result(const char	*buffer, unsigned int	start)
{//startはsave_bufferを呼び出す前にgnlの最初で取得しておく。
	size_t			len;
	char			*result;

	len = ft_strlen(buffer);
    while (buffer[len] != '\n' && len >= 0)
    	len--;
    if ((size_t)start == len + 1)
    {
        while (buffer[len] != '\0')
			len++;
    }
	len = len - start;
	result = ft_substr(buffer, start, len + 1);
	if (!result)
		return (NULL);
	return (result);
}
