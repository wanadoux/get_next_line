#include "get_next_line.h"

size_t ft_strlen(const char * str)
{
    int i;
    
    i = 0;
    if (!str)
        return(i);   
    while (str[i])
        i++;
    return(i);
}

char    *ft_strchr(const char *str, int c)
{
    while (*str && *str != (char)c)
        str++;
    if (*str == (char)c)
        return((char *)str);
    return(NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t end)
{
	char			*sstr;
	unsigned int	i;

	sstr = NULL;
	if (!s)
		return (NULL);
	if (end + start > ft_strlen(s))
		end = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		end = 0;
	sstr = (char *)malloc((end + 1) * sizeof(char));
	if (sstr == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < end)
	{
		sstr[i] = s[start + i];
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
    if(s1)
	{
        while (s1[i])
	    {
		    str[j++] = s1[i++];
	    }
        i = 0;
    }
	if(s2)
    {
        while (s2[i])
	    {
		    str[j++] = s2[i++];
	    }
    }
	str[j] = '\0';
	return (str);
}
