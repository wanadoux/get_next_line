/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:09:01 by cboma-ya          #+#    #+#             */
/*   Updated: 2024/08/15 14:13:07 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	reinit_buff(char *buff)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(buff);
	if (!buff[i])
		buff[0] = '\0';
	else
	{
		while (buff[i])
			buff[j++] = buff[i++];
		buff[j] = '\0';
	}
}

char	*read_get_line(int fd, char *line, char *buffer)
{
	int		bytes_read;
	char	*new_line;

	bytes_read = 1;
	new_line = ft_strchr(line, '\n');
	while (!new_line && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
			return (line);
		if (bytes_read < 0)
			return (free(line), NULL);
		buffer[bytes_read] = '\0';
		new_line = ft_strchr(buffer, '\n');
		line = ft_strjoin_nl(line, buffer);
		reinit_buff(buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strcpy_nl(buffer[fd]);
	reinit_buff(buffer[fd]);
	line = read_get_line(fd, line, buffer[fd]);
	if (!line)
		return (NULL);
	return (line);
}
