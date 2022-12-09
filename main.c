#include "get_next_line.h"



int main (void){

    char *line;


    int fd;
    fd = open("text", O_RDONLY);
    line = get_next_line(fd);

    free(line);
    close(fd);
    return 0;
}
