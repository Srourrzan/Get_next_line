#include "get_next_line.h"

int main()
{
    int fd;

    //printf("staring the program...\n");
    //printf("Reading data from test.txt file.\n");
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    char *line;
    //printf("Printing line by line\n");
    //printf("\nStarting get_next_line\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return(0);
}
