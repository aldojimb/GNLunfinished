#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>


char	*get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s1);
char    *ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *s);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 15

#endif
