#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

void myls()
{
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("opendir");
    }
    else
    {
        struct dirent *pDirent = NULL;
        while (1)
        {
            pDirent = readdir(dir);
            if (NULL == pDirent)
            {
                break;
            }
            //排除当前目录“.”和上级目录“..”
            if (strcmp(pDirent->d_name, ".") != 0 && strcmp(pDirent->d_name, ".."))
            {
                printf("\t%s\n", pDirent->d_name);
            }
        }
    }
    printf("\n");
}

int mycp(char filename[128], char space[128])
{
    int fd = open(filename, O_RDONLY);
    if (-1 == fd)
    {
        perror("open");
        return 0;
    }
    int destfd = open(space, O_WRONLY | O_CREAT, 0777);
    if (-1 == destfd)
    {
        perror("open dest");
        return 0;
    }
    ssize_t ret = -1;
    char cabuf[1024] = {'\0'};
    while (1)
    {
        memset(cabuf, 0, sizeof(cabuf));
        ret = read(fd, cabuf, sizeof(cabuf));
        if (ret > 0)
        {
            write(destfd, cabuf, ret);
        }
        else if (0 == ret)
        {
            break;
        }
        else
        {
            perror("read file");
            break;
            return 0;
        }
    }
    close(fd);
    close(destfd);
    return 1;
}

int main(int argc, char const *argv[])
{
    system("clear");
    while (1)
    {
        struct passwd *pwd;
        pwd = getpwuid(getuid());
        printf("\033[36m(\033[32m(%s)\033[36m)\033[33m>\033[37m>\033[0m", pwd->pw_name);
        char dosomething[128];
        memset(dosomething, 0, 128);
        scanf("%s", dosomething);
        if (strcmp(dosomething, "ls") == 0)
        {
            myls();
        }
        else if (strcmp(dosomething, "cp") == 0)
        {
            char filename[128];
            char space[128];
            printf("要拷贝文件名：");
            scanf("%s", filename);
            printf("目的文件夹是：");
            scanf("%s", space);
            strcat(space, "/");
            strcat(space, filename);
            if (mycp(filename, space) == 1)
            {
                printf("%s拷贝成功\n", filename);
            }
        }
        else
        {
            printf("命令%s错误,请重试\n", dosomething);
        }
    }
    return 0;
}
