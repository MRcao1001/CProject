#include "public.h"

int main(int argc, char const *argv[])
{
    int mk_out = mkfifo("stationAB", 0777);
    int mk_in = mkfifo("stationBA", 0777);
    if (mk_in == -1 || mk_out == -1)
    {
        if (EEXIST != errno)
        {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    int fd_out = open("stationBA", O_RDWR);
    int fd_in = open("stationAB", O_RDWR);
    if(fd_in ==-1 || fd_out == -1){
        exit(EXIT_FAILURE);
    }
    //数据向管道写
    pid_t pid1 = fork();
    /*----------------------------------------进程1部分star------------------------------*/
    if (pid1 == 0)
    {
        //子从管道读取数据
        char stream[64] = {"\0"};
        while (1)
        {
            memset(stream, 0, 64);
            read(fd_in, stream, 64);
            if (strcmp("quit", stream) == 0)
            {
                printf("【----系统提示：对方已经下线，您已经退出聊天！----】\n");
                break;
            }
            printf("A: %s\n\n", stream);
        }
    }
    /*---------------------------------------进程1部分end------------------------------*/

    else if (pid1 > 0)
    {
        //主进程写数据到管道
        /*---------------------------------------进程2部分star------------------------------*/
            if (fd_out > 0)
            {
                char stream[64] = {"\0"};
                while (1)
                {
                    scanf("%s", stream);
                    if (0 == strcmp("quit", stream))
                    {
                        write(fd_out, stream, strlen(stream));
                        break;
                    }
                    write(fd_out, stream, strlen(stream));
                }
            }
        /*---------------------------------------进程2部分end------------------------------*/


    }
    else
    {
        perror("fork1");
    }
    close(fd_in);
    close(fd_out);
    return 0;
}
