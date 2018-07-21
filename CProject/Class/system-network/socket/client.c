#include "public.h"
//socket头文件
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>  //htons
#include <netinet/in.h> //inet_addr
//服务器地址193.112.137.246 root@debian(127.0.0.1)
int sockfd;
char recdata[100];
//定义一个结构体
typedef struct Info
{
    char data[32];
    struct info *pNext;
} Info;

//产生节点
Info *makeInfo()
{
    Info *info = (Info *)malloc(sizeof(Info));
    if (NULL == info)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    memset(info, 0, sizeof(Info));
    return info;
}

//给节点赋值
int getinfo(Info *temp)
{
    printf("请输入:");
    scanf("%s", temp->data);
    return 0;
}

//插入节点(头插)
int addinfo(Info *headInfo)
{
    if (NULL == headInfo)
    {
        perror("headinfo is null");
        return -1;
    }

    Info *newInfo = makeInfo();
    getinfo(newInfo);

    //创建链表
    newInfo->pNext = headInfo->pNext;
    headInfo->pNext = newInfo;
    newInfo = NULL;
    return 0;
}

//将链表所有数据写入socket
void writeInfo(Info *headInfo)
{
    if (NULL == headInfo || NULL == headInfo->pNext)
    {
        perror("is null");
        return;
    }

    Info *p = headInfo->pNext;
    while (NULL != p)
    {
        write(sockfd, p->data, sizeof(p->data));
        int recvbitys = recv(sockfd, recdata, 100, 0);
        if ((recvbitys) == -1)
        {
            perror("rec error");
            exit(EXIT_FAILURE);
        }
        recdata[recvbitys] = '\0';
        printf("rec: %s", recdata);
        p = p->pNext;
        sleep(1);
    }
}
int main(int argc, char const *argv[])
{
    //产生一个头结点
    Info *headInfo = makeInfo();
    //向链表插入五句话
    int i = 5;
    while (i)
    {
        if (0 == addinfo(headInfo))
        {
            printf("make a node\n");
            sleep(1);
            i--;
            continue;
        }
        printf("error!\n");
        break;
    }

    //产生socket文件
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sockfd)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8888);
    servAddr.sin_addr.s_addr = inet_addr("193.112.137.246");
    bzero(servAddr.sin_zero, 8);

    int ret = connect(
        sockfd,
        (struct sockaddr *)&servAddr,
        sizeof(servAddr));
    if (-1 == ret)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    printf("connect successful\n");

    char senddata[] = {"hello server!\n"};

    writeInfo(headInfo);
    close(sockfd);
    return 0;
}