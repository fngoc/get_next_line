/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fngoc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:39:41 by fngoc             #+#    #+#             */
/*   Updated: 2020/11/08 12:39:43 by fngoc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h> /* Для printf */
# include <fcntl.h> /* Для open */
# include <unistd.h> /* Для  */
# include <stdlib.h> /* Для malloc и free */
# define BUFFER_SIZE 50

size_t	ft_strlen(const char *s);

void	ft_strclr(char *s);

char	*ft_strnew(unsigned int size);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

char	*chek_line(char *static_str, char **line);

int		get_next_line(int fd, char **line);

#endif
