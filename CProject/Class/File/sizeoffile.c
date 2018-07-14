#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    int fd = open(argv[1],O_RDONLY);
    if(-1 == fd){
        perror("open file");
        exit(EXIT_FAILURE);

    }
    off_t offset = lseek (fd, 0, SEEK_END);
    if((off_t)-1 == offset){
        perror("lseek");
    }
    else{
        printf("%s: size --> %ldbit\n",argv[1],offset);
    }
    return 0;
}
