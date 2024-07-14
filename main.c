#include "get_next_line.h"

int main(void)
{
    int fd;
    int count;
    char * next_line;

    count = 0;
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("error occcured");
        return(1);
    }
    while(1)
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            break ;
        count++;
        printf("[%d]:%s\n", count, next_line);
        next_line = NULL;
    }
    free(next_line);    
    close(fd);
    return(0);
}