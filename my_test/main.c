#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);

	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);

	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);

	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);

	printf("result = %d\n", get_next_line(fd, &line));
	printf("%s\n\n", line);
	free(line);

	while (1)
	{}
	return (0);
}
