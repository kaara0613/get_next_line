/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:01:02 by kaara             #+#    #+#             */
/*   Updated: 2024/07/02 19:05:16 by kaara            ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*srccpy;
	size_t	size;

	size = ft_strlen(src);
	srccpy = (char *)malloc(size + 1);
	if (!srccpy)
		return (NULL);
	ft_strlcpy(srccpy, src, size + 1);
	return (srccpy);
}
