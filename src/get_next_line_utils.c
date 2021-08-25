#include "get_next_line.h"

/*
** ft_strlen: возвращает количество символов в строке.
*/

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		++i;
	return (i);
}

/*
** ft_strnew: создает новую строку размером size
** и заполняет ее нулями.
*/

char	*ft_strnew(unsigned int size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

/*
** ft_strcpy: копируют строку src в dst включая '\0'.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

/*
** ft_strdup: дублирует строку, на
** которую указывает аргумент str.
*/

char	*ft_strdup(const char *s1)
{
	char	*str_dup;
	char	*p;

	str_dup = malloc(ft_strlen(s1) + 1);
	p = str_dup;
	if (str_dup == NULL)
		return (NULL);
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (str_dup);
}

/*
** ft_substr:  выделяет и возвращает новую строку,
** которая является результатом конкатенации
** из 's1' и 's2'.
*/

char	*ft_strjoin_fix(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(p = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		++i;
		++j;
	}
	p[i] = '\0';
	return (p);
}
