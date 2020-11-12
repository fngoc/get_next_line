/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:16:41 by fngoc             #+#    #+#             */
/*   Updated: 2020/11/11 12:16:48 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** ft_strclr: очищает строку.
*/

void	ft_strclr(char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
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

char	*chek_line(char **static_str, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (*static_str)
		if ((p_n = ft_strchr(*static_str, '\n')))
		{
			*p_n++ = '\0';
			*line = ft_strdup(*static_str);
			if (*p_n)
				ft_strcpy(*static_str, p_n);
			else
				ft_strclr(&(*static_str));
		}
		else
		{
			*line = ft_strdup(*static_str);
			ft_strclr(&(*static_str));
		}
	else
		*line = ft_strnew(0);
	return (p_n);
}

/*
** chek_line: читает строку, прочитанную из
** дескриптора файла, остонавливаясь на '\n'
** прочитаная строка без '\n'.
*/

int		get_next_line(int fd, char **line)
{
	static char	*static_str[1024];
	char		*buf;
	char		*p_n;
	int			end_read;

	if (BUFFER_SIZE <= 0 || !line || !(buf = malloc(BUFFER_SIZE + 1))
		|| fd > 1023 || (-1 == read(fd, buf, 0)))
		return (-1);
	p_n = chek_line(&static_str[fd], line);
	while (!p_n && (end_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[end_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n++ = '\0';
			if (*p_n && !(static_str[fd] = ft_strdup(p_n)))
				return (-1);
		}
		if (!(*line = ft_strjoin_fix(*line, buf)))
			return (-1);
	}
	free(buf);
	return (p_n ? 1 : 0);
}