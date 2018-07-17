#include "../public.h"
#include <sys/mman.h>

int main(int argc, char const *argv[])
{
    int fd = open(argv[1], O_RDWR);
    if (-1 == fd)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    //1:where the file will be map for?
    //*NULL means anto map
    //2:size of  memory which will be map
    //3:what is effect of the map which is maped
    //4:set the changes of data in memory can be read in other porcess is SHARE or PRIVATE
    //5:the file's pointer
    //6:where is the map begin with
    //*file must biger than 1024B
    void *addr = mmap(NULL, 1024,
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED,
                      fd, 0);
    if (MAP_FAILED == addr)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    char *data = "123,123,123";
    strcpy((char *)addr, data);

    munmap(addr, 1024);
    close(fd);
    return 0;
}
