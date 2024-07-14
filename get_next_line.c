#include "get_next_line.h"

char    *get_line(char *line)
{
    static char    *temp;
    size_t  all;
    size_t  j;
    
    temp = ft_strjoin(temp, line);
    if (!temp)
    {
        free(temp);
        return(NULL);
    }
    all = ft_strlen(temp);
    j = ft_strlen(ft_strchr(temp, '\n'));
    if (j > 0)
    {
        line = ft_substr(temp, 0, (all - j));
        temp = ft_substr(temp, (all-j+1), all);
        return(line);
    }
    return(temp);
}

char    *read_line(int fd, char * buffer)
{
    int     bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
        return(NULL);
    return(buffer);
}

char    *get_next_line(int fd)
{
    char    buffer[BUFFER_SIZE+1];
    char    *line;

    line = read_line(fd, buffer);
    if (line == NULL)
    {
        free(line);
        return(NULL);
    }
    line = get_line(line);
    return(line);
}
