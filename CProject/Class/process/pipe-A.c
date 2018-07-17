#include "public.h"

int main(int argc, char const *argv[])
{
    int fd = open("pipefile",O_RDWR);
    if(fd >0){
        char stream[64]={"\0"};
        while(1){
            printf(">>:");
            scanf("%s",stream);
            if(strcmp("quit",stream)==0){
                write(fd,stream,strlen(stream));
                break;
            }
            write(fd,stream,strlen(stream));
            printf("消息收取中...\n");
            sleep(1);
            memset(stream,0,64);
            read(fd,stream,64);
            if(strcmp("quit",stream)==0){
                break;
            }
            printf("B:%s\n",stream);
        }
        close(fd);
    }
    return 0;
}
