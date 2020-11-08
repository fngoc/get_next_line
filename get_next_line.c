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

#include "get_next_line.h"

/*
** ft_strclr: очищает строку.
*/

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

/*
** ft_strchr: возвращает указатель на первое
** вхождение символа c в строку, на которую
** указывает s.
*/

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp;
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			tmp = &s[i];
			return ((char *)tmp);
		}
		++i;
	}
	if (c == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}

/*
** chek_line: проверка.
*/

char	*chek_line(char *static_str, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (static_str)
		if ((p_n = ft_strchr(static_str, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(static_str);
			ft_strcpy(static_str, ++p_n);
		}
		else
		{
			*line = ft_strdup(static_str);
			ft_strclr(static_str);
		}
	else
		*line = ft_strnew(1);
	return (p_n);
}

/*
** chek_line: читает строку, прочитанную из
** дескриптора файла, остонавливаясь на '\n'
** прочитаная строка без '\n'.
*/

int		get_next_line(int fd, char **line)
{
	static char	*static_str;
	char		buf[BUFFER_SIZE + 1];
	char		*p_n;
	char		*tmp_for_free;
	int			end_read;

	p_n = chek_line(static_str, line);
	while (!p_n && (end_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[end_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			static_str = ft_strdup(++p_n);
		}
		tmp_for_free = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp_for_free);
	}
	return ((end_read || ft_strlen(static_str) || ft_strlen(*line)) ? 1 : 0);
}

int		main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
