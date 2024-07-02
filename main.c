// #include "get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("test.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return 1;
//     }
//     char *line;
//     line = get_next_line(fd);
//     printf("%s\n", line);
//     free(line);

//     close(fd);
//     return 0;
// }
