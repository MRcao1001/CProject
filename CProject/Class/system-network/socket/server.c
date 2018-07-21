#include "public.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char const *argv[])
{
    //循环监听客户端的连接
    //循环检查是否有客户端连接到服务器
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sockfd){
        perror("socket");
        exit(EXIT_FAILURE);

    }
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8888);
    servAddr.sin_addr.s_addr = inet_addr("192.168.27.126");
    bzero(servAddr.sin_zero,8);
    int ret = bind(
        sockfd,
        (struct sockaddr*)&servAddr,
        sizeof(servAddr)
    );
    if(-1 == ret){
        perror("bind");
        exit(EXIT_FAILURE);
    }

    //设置sockfd处理监听状态
    //并设置客户端连接队列的最大缓冲数
    ret = listen(sockfd,20);
    if(-1 == ret){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in clientAddr;
    int clientSockfd = -1;
    int iLen = sizeof(clientAddr);
    char caMsg[64] = {'\0'};
    while(1){
        //接收通过sockfd监听到的客户端连接
        //并且自动将客户端的相应信息填入clientAddr
        //连接成功产生一个新的socket
        //用于客户端和服务器进行数据交互
        printf("accepting client ...\n");
        //如果没有连接则阻塞等待
        clientSockfd = accept(
            sockfd,
            (struct sockaddr*)&clientAddr,
            &iLen);
        if(-1 == clientSockfd){
            perror("accept");
            break;
        }
        //inet_ntoa:将整数表示的IP转换为点分十进制字符串表示
        printf("client ip:%s,   port:%u,    connect success     new sockfd = %d\n",
        inet_ntoa(clientAddr.sin_addr),
        clientAddr.sin_port,
        clientSockfd);

        memset(caMsg, '\0', sizeof(caMsg));
        //接收客户端的数据
        read(clientSockfd,caMsg,sizeof(caMsg));
        strcat(caMsg,"!!! >_< !!!");
        //发送数据给客户端
        write(clientSockfd,caMsg,strlen(caMsg));

    }
    return 0;
}
