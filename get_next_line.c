#include "get_next_line.h"

char	*ft_actual(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[0] == '\0')
		return (NULL);
	ptr = malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

char	*after(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	i = ft_strlen(str);
	j = 0;
	while (str[j] != '\n' && str[j])
		j++;
	ptr = malloc(sizeof(char) * (i - j));
	if (!ptr)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}

int	check_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_read(int fd, char *buf, char *tmp, char *str)
{
	int		i;

	i = 1;
	while (i != 0 || check_newline(str) != 1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = str;
		if (!tmp)
		{
			tmp = malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 0x7fffffff)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(fd, buf, tmp, str);
	if (!str)
		return (NULL);
	line = ft_actual(str);
	str = after(str);
	return (line);
}