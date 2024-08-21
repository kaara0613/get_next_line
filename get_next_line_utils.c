/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:01:02 by kaara             #+#    #+#             */
/*   Updated: 2024/08/21 14:26:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	str_len;

	str_len = 0;
	if (!*str)
		return (str_len);
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

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + len);
	while (len > 0)
	{
		len--;
		if (s[len] == (char)c)
			return ((char *)s + len);
	}
	return (NULL);
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
