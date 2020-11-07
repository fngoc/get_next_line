/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <fngoc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:33:25 by fngoc             #+#    #+#             */
/*   Updated: 2020/11/07 18:16:53 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h> /* Для open */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	get_next_line(int fd, char **line)
{
	char	buf[100];
	int		end_read;

	while ((end_read = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			break ;
		buf[end_read] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
