
#ifndef GET
# define GET

# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 10
#endif

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <limits.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buf, char *tmp, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const	char *str);
char	*ft_actual(char *str);
char	*after(char *str);
int		check_newline(char *str);

#endif