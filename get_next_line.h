#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char    *get_next_line(int fd);
int	    ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strchri(const char *s, int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*get_extract(char **str);
void 	*ft_free(char **str);
char 	*ft_getline(char *str);
char 	*ft_cutline(char *str);
int new_check(const char *s);
#endif