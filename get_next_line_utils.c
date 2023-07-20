#include "get_next_line.h"

int	ft_check(char *s, int byte)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		return (i + 1);
	if (byte == 0)
		return (i);
	return (0);
}
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int	i;
	int	s_len;

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*mem;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2 || !(mem = malloc((ft_strlen(s1) + (ft_strlen(s2) + 1)))))
		return (NULL);
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	while (s2[j])
		mem[i++] = s2[j++];
	mem[i] = '\0';
	free(s1);
	return (mem);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
char *ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (*str);
}