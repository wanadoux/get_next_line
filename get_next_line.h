#ifndef GET_NEXT_LINE_H
    #define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 4
#endif

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char    *get_next_line(int fd);
char    *ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t end);

size_t  ft_strlen(const char * str);

#endif