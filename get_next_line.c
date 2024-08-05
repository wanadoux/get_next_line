/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 04:52:43 by cboma-ya          #+#    #+#             */
/*   Updated: 2024/08/05 12:04:14 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *line)
{
	int			rest;
	int			all;
	static char	*temp;
	char		*old_temp;

	old_temp = temp;
	temp = ft_strjoin(temp, line);
	free(old_temp);
	if (!temp)
		return (NULL);
	all = ft_strlen(temp);
	rest = ft_strlen(ft_strchr(temp, '\n'));
	if (rest > 0)
	{
		line = ft_substr(temp, 0, (all - rest + 1));
		old_temp = temp;
		temp = ft_substr(temp, (all - rest + 1), all);
		free(old_temp);
		return (line);
	}
	return (temp);
}

char	*read_line(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0 && buffer == NULL)
		return (NULL);
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*test;
	static char	*line = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		test = read_line(fd, buffer);
		if (!test)
			break ;
		line = get_line(test);
		if (ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}
/*
		test = read_line(fd, buffer);
		if (!test)
			return (NULL);
		if (test == NULL)
			return (line);
		else
			line = test;
		line = get_line(line);
		if (!(ft_strchr(line, '\n') > 0))
		{
			//	printf("test1\t%s\n", line);
			line = get_next_line(fd);
			//	printf("test2\t%s\n", line);
		}
		return (line);
 }*/

/* char	*destrucsdefou(char *temp, int nbyte, int fd)
{
	int		i;
	int		j;
	char	*buf;

	int reminder; // le reste dans le temp, apres le \n
	i = read(fd, buf, nbyte);
	temp = ft_strjoin(temp, buf);
	ft_strchr(temp, '\n');
} */