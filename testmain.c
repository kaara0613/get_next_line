/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:28:48 by kaara             #+#    #+#             */
/*   Updated: 2024/08/22 23:33:19 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*make_result(const char	*buffer, size_t	start)
{//startはsave_bufferを呼び出す前にgnlの最初で取得しておく。
	size_t			len;
	char			*result;

	if (!buffer || buffer[start] == '\0')
    	return (NULL);
    len = start;
	while(buffer[len] != '\n' && buffer[len] != '\0')
		len++;
    len = len - start;
	result = ft_substr(buffer, start, len + 1);
	if (!result)
		return (NULL);
	return (result);
}

int	main(void)
{
	char *str = "hello world\nhello\nhello\nhello";
	char *result;
    result = make_result(str, 11);
    printf("%s", result);
}