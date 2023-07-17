#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# define BUFFER_SIZE 20

int	ft_check(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len > s_len - start)
		len = s_len - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char *get_next_line(int fd)
{
	static char *str = "";
    char *return_string;
    int ft_check_value;


    ft_check_value = ft_check(str);

    str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!str)
        return (NULL);
	if (!ft_check_value)
        read(fd, str, BUFFER_SIZE);
    return_string = malloc(sizeof(char)* (ft_check_value + 1));
    return_string = ft_substr(str,0,ft_check(str));
    return (return_string);
}

int main()
{
	int fd;

	fd = open("a.txt", O_RDONLY, 0777);
	char *a = get_next_line(fd);
	printf("%s", a);
    close(fd);
    return (0);
}