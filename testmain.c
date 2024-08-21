/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:28:48 by kaara             #+#    #+#             */
/*   Updated: 2024/08/21 17:48:35 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <libc.h>

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

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("test.txt", O_RDONLY);
    printf("1/n");

    printf("%d/n", fd);
    printf("2/n");
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}