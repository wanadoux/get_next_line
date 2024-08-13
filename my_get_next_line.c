/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 04:52:43 by cboma-ya          #+#    #+#             */
/*   Updated: 2024/08/13 14:34:31 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *line)
{
	char	*temp;
	int		rest;
	int		all;
	char	*old_line;

	all = ft_strlen(line);
	if (ft_strchr(line, '\n'))
	{
		rest = ft_strlen(ft_strchr(line, '\n'));
		line = ft_substr(line, 0, (all - rest + 1));
		temp = ft_substr(line, (all - rest + 1), all);
		printf("line w /n : %s\n", line);
		return (line);
	}
	printf("temp no /n : %s\t line: %s\n", temp, line);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_line(int fd, char *line, char *buffer)
{
	int	bytes_read;

	while (!(ft_strchr(buffer, '\n') && bytes_read))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
			return (line);
		if (bytes_read < 0)
			return (free(line), NULL);
		printf("line read /n : %s\n", line);
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
		printf("line join /n : %s\n", line);
	}
	printf("line read /n : %s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*pre_line;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pre_line = read_line(fd, line, buffer);
	if (!pre_line)
		return (NULL);
	if (pre_line == NULL)
		return (line);
	else
		line = pre_line;
	line = get_line(line);
	if (!(ft_strchr(line, '\n') > 0))
	{
		printf("test1\t%s\n", line);
		line = get_next_line(fd);
		printf("test2\t%s\n", line);
	}
	return (line);
}
/*
while (1)
{
	pre_line = read_line(fd, buffer, &bytes_read);
	printf("%s", pre_line);
	if (bytes_read < BUFFER_SIZE && bytes_read > -1)
	{
		line = ft_strjoin(line, pre_line);
		break ;
	}
	if (!pre_line)
	{
		break ;
		// 	if (line && *line)
		// 	{
		// 		last_line = get_line("");
		// 		if (pre_line && (ft_strchr(last_line, '\n') == NULL))
		// 			return (last_line);
		// 		return (line);
		// 	}
		// 	return (NULL);
		// }
		line = get_line(pre_line);
		if (line == NULL)
			break ;
		if (ft_strchr(line, '\n'))
			break ;
	}
}
return (line);
}


	char	*destrucsdefou(char *temp, int nbyte, int fd)
	{
		int		i;
		int		j;
		char	*buf;

		int reminder; // le reste dans le temp, apres le \n
		i = read(fd, buf, nbyte);
		temp = ft_strjoin(temp, buf);
		ft_strchr(temp, '\n');
	}*/
