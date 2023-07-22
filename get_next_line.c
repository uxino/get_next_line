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
	return (i);
}

char *ft_getline(char *s)
{
	int	i;
	char *arr;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '\n')
			break;
	}
	if (s[i] == '\n')
		i++;
	arr = malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while(s[i] && s[i] != '\n')
	{
		arr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
char *ft_cutline(char *str)
{
	char *cuttedline;
	int start = ft_check(str,'\n');
	int len = (ft_strlen(str) - ft_check(str, '\n'));
	if (len == 0)
	{
		free(str);
		return (NULL);
	}
	cuttedline = ft_substr(str, start, len);
	//printf("{cutted line: %s}\n ",cuttedline);
	//ft_free(&str);
	free(str);
	return (cuttedline);
}

char *get_next_line(int fd)
{
    static char *str = NULL;
    char *temp;
    int byte;
	char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    byte = 1;
    while (!new_check(str) &&  byte != 0)
    {
        byte = read(fd, temp, BUFFER_SIZE);
        if (byte == -1)
		{
			if (str)
				free(str);
				str = NULL;
			free(temp);
            return (NULL);
		}
        temp[byte] = '\0';
        str = ft_strjoin_gnl(str, temp);
	}
	free(temp);
	if (!str || !*str)
	{
		if (str)
			free(str);
		str = NULL;
		return (NULL);
	}
	line = ft_getline(str);
	str = ft_cutline(str);
    return (line);
}
