#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int	    ft_check(char *s, int byte);
char    *get_next_line(int fd);
int	    ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*get_extract(char **str);
#endif