#include "get_next_line.h"

int ft_check(char *s,int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	return (0);
}

char *ft_getline(char *str)
{
	char *line;

	line = ft_substr(str,0,ft_check(str,'\n'));
	//printf("{line: %s}\n ",line);
	return (line);
}
char *ft_cutline(char *str)
{
	char *cuttedline;
	int start = ft_check(str,'\n');
	int len = (ft_strlen(str) - ft_check(str, '\n'));
	
	cuttedline = ft_substr(str, start, len);
	//printf("{cutted line: %s}\n ",cuttedline);
	//ft_free(&str);
	free(str);
	str = NULL;
	return (cuttedline);
}

char *get_next_line(int fd)
{
    static char *str;
    char temp[BUFFER_SIZE + 1];
    int byte;
	char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    if (!str)
        str = ft_strdup("");
    byte = 1;
    while (!ft_strchr(str, '\n') && byte != 0)
    {
        byte = read(fd, temp, BUFFER_SIZE);
        if (byte == -1)
            return (ft_free(&str));
        temp[byte] = '\0';
        str = ft_strjoin(str, temp);
    }
	line = ft_getline(str);
	str = ft_cutline(str);
    if (str[0] == '\0')
        ft_free(&str);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
    return (line);
}
/*
int main()
{
	int fd = open("file.txt", O_RDONLY);
 	char *line = get_next_line(fd);

	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
 	close(fd);
	//system("leaks a.out");
}
*/