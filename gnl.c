#include "get_next_line.h"

char *get_next_line(int fd){

char buffer[BUFFER_SIZE + 1]; // +1 for the null terminator
ssize_t bytes_read; // number of bytes read from the file
char *line; // pointer to the line that will be returned
static char *remainder; // static variable to store the remainder of the string


// check if fd and BUFFER_SIZE are valid
if (fd < 0 || BUFFER_SIZE <= 0)
    return NULL;

// check if there is a remainder
if (remainder)
  {
    line = ft_strdup(remainder);
    free(remainder);
    remainder = NULL;
  }
else
    line = ft_strdup("");

//check if line has been allocated
if (!line)
    return NULL;

// read from the file until a newline is found or the end of the file is reached
while ((ft_strchr(line, '\n')) == NULL)
{
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read < 0) // check if there was an error reading the file
    {
        free(line);
        remainder = NULL;
        return NULL;
    }
    if (bytes_read != 0){
    buffer[bytes_read] = '\0';

    remainder = ft_strjoin(line, buffer);
    free(line);
    line = remainder;
    }
    else // if the end of the file is reached
    {
        remainder = NULL;
        return ft_strjoin(line, buffer);
    }
}

//separate the line from the remainder
if (ft_strchr(line, '\n'))
{
    remainder = ft_strdup(ft_strchr(line, '\n') + 1);
    *(ft_strchr(line, '\n')+1) = '\0';
}
else
    remainder = NULL;

printf("line: %s", line);
printf("remainder: %s", remainder);

return line;
}
