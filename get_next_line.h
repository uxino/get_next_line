#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 20

#include <fcntl.h>
#include <stdlib.h>

// get next line
int	ft_check(char *s);
char *get_next_line(int fd);
#endif