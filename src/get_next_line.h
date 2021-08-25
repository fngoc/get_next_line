#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);

void	ft_strclr(char **s);

char	*ft_strnew(unsigned int size);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *s1);

char	*ft_strjoin_fix(char *s1, char *s2);

char	*ft_strchr(const char *s, int c);

char	*chek_line(char **static_str, char **line);

int		get_next_line(int fd, char **line);

#endif
