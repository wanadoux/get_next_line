/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:27 by cboma-ya          #+#    #+#             */
/*   Updated: 2024/08/15 14:13:55 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strcpy_nl(char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	if (!str || !*str)
		return (NULL);
	cpy = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (*str && *str != '\n')
		cpy[i++] = *str++;
	if (*str == '\n')
		cpy[i++] = '\n';
	cpy[i] = '\0';
	return (cpy);
}

/*locates the first occurence of c (converted to a char)
in the string pointed to by s.
The terminating null character is considered to be part of the string;
therefor if c is '\0', the function locate the terminating '\0'
*/
char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (0);
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
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

/*
Allocate (with malloc(3)) and returns a new string
resulting from the concatenation of s1 and s2.
*/
char	*ft_strjoin_nl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	j = 0;
	if (!str)
		return (free(s1), NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
			str[j++] = s1[i++];
		free(s1);
	}
	i = 0;
	if (s2)
	{
		while (s2[i] && s2[i] != '\n')
			str[j++] = s2[i++];
		if (s2[i] == '\n')
			str[j++] = '\n';
	}
	str[j] = '\0';
	return (str);
}
