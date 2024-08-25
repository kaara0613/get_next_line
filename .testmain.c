/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .testmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:28:48 by kaara             #+#    #+#             */
/*   Updated: 2024/08/25 23:12:59 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		read_buffer, ft_strlen(read_buffer));
	return (new_buffer);
}

int	main(void)
{
	char *buffer = "abcdefghijklmnopqrstuvwxy";
	char *read_buffer = "z";
    *buffer = gnl_realloc(*buffer, read_buffer);
    printf("%s", buffer);
	return 0;
}

// あと1文字readしないといけないのに出力できずに無限ループに陥る
// この無限ループはgnlがNULLを返さないことで陥る