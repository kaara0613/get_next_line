/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:28:48 by kaara             #+#    #+#             */
/*   Updated: 2024/08/21 14:39:28 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <libc.h>

int main(void)
{
    char	*line;
    int		fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    while(1)
    {
    	line = get_next_line(fd);
        if (line == NULL)
        	break ;
    	printf("%s\n", line);
    	free(line);
    }
    close(fd);
    return 0;
}