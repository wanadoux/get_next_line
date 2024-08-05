/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboma-ya <cboma-ya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:25:01 by cboma-ya          #+#    #+#             */
/*   Updated: 2024/07/26 03:07:45 by cboma-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int			fd;
	char		*line;
	static int	line_read;

	line_read = 0;
	fd = 0;
	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("[%d]:%s\n", ++line_read, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
/*
int	main(void)
{
	int		fd;
	char	*next_line;
	int		line_read;

	line_read = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("(null)");
		return (1);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		if (!(next_line == NULL))
		{
			line_read++;
			printf("[%d]:%s\n", line_read, next_line);
		}
		next_line = NULL;
	}
	close(fd);
	return (0);
}*/