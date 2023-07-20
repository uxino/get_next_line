#include "get_next_line.h"

char	*get_extract(char **str)
{
	char	*next_line; 
	char	*line;

	next_line = ft_strchr(*str, '\n');
	if (next_line)
	{	
		line = ft_substr(*str, 0, next_line - *str + 1);
		ft_free(str);
		*str = ft_strdup(next_line+1);
	}
	else
	{
		line = ft_strdup(*str);
		ft_free(str);
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char *str;
    char temp[BUFFER_SIZE + 1];
	int	byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	byte = 1;
	while (!ft_strchr(str, '\n') && byte > 0)
	{
    	byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
			return (ft_free(&str));
		temp[byte] = '\0';
		str = ft_strjoin(str, temp);
	}
	if (!str[0])
		return (ft_free(&str));
    return (get_extract(&str));
}

// int main()
// {
// 	int fd = open("/Users/museker/francinette/tests/get_next_line/fsoares/1char.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));

// 	close(fd);


// }

