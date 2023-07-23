#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_getline(char *s);
char	*ft_cutline(char *str);
int		new_check(const char *s);
char	*ft_read(char *str, int fd);
#endif