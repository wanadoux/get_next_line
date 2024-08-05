/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 05:05:10 by cboma-ya          #+#    #+#             */
/*   Updated: 2024/07/23 00:49:52 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
allocates sufficient memory for a copy of the string s1, does the copy,
and returns a pointer to it.
The pointer may subsequently be used as an argument to the function free(3).
If insufficient memory is available, NULL is returned
*/
char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(const char) * ft_strlen(s) + 1);
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*locates the first occurence of c (converted to a char)
in the string pointed to by s.
The terminating null character is considered to be part of the string;
therefor if c is '\0', the function locate the terminating '\0'
*/
char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

/*donne taille de la string str.*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
Allocate (with malloc(3)) and returns a new string
resulting from the concatenation of s1 and s2.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	j = 0;
	if (!str)
		return (free(str), NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
			str[j++] = s1[i++];
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
			str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}

/*
Alloue (avec malloc(3)) et retourne une chaîne de
caractères issue de la chaîne ’s’.
Cette nouvelle chaîne commence à l’index ’start’ et
a pour taille maximale ’end’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t end)
{
	unsigned int	i;
	char			*sstr;

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
