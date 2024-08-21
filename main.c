/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:17:42 by kaara             #+#    #+#             */
/*   Updated: 2024/08/21 13:12:53 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <libc.h>

// int main(void)
// {
//     char	*line;
//     int		fd = open("test.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return 1;
//     }
//     while(1)
//     {
//     	line = get_next_line(fd);
//         if (line == NULL)
//         	break ;
//     	printf("%s\n", line);
//     	free(line);
//     }
//     close(fd);
//     return 0;
// }
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ministr;
	size_t	actual_len;

	actual_len = ft_strlen(s);
	if (actual_len <= start)
	{
		ministr = (char *)malloc(1);
		if (ministr)
			ministr[0] = '\0';
		else
			return (NULL);
		return (ministr);
	}
	if (actual_len - start < len)
		len = actual_len - start;
	ministr = (char *)malloc(len + 1);
	if (!ministr)
		return (NULL);
	ft_strlcpy (ministr, s + start, len + 1);
	return (ministr);
}

char	*make_result(char	*buffer, unsigned int	start)
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

int main (void)
{
	char *str = "world";
    char *result;

    result = make_result(str, 0);
	printf("%s", result);
    return (free(result), 0);
}
