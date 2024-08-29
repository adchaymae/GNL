#include "get_next_line.h"
int main(){
    char *line;
    char *line2;
    int fd1 = open("file.txt", O_RDONLY);
    int fd2 = open("n.txt", O_RDONLY);
    while(1)
    {    line = get_next_line(fd1);
        line2 = get_next_line(fd2);
        if(line == NULL) 
            break;
        if (line2 == NULL)
            break;
        printf("line1: %s==",line);
        printf("line2: %s", line2);
    }

}