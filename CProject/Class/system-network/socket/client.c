#include "public.h"
//socket头文件
#include <sys/types.h>         
#include <sys/socket.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr
//服务器地址193.112.137.246 root@debian 
int main(int argc, char const *argv[])
{
    //产生socket文件
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sockfd){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8888);
    servAddr.sin_addr.s_addr = inet_addr("193.112.137.246");
    bzero(servAddr.sin_zero,8);

    int ret = connect(
        sockfd,
        (struct sockaddr*)&servAddr,
        sizeof(servAddr)
    );
    if(-1 == ret){
        perror("connect");
        exit(EXIT_FAILURE);
    }
    printf("connect successful\n");

    char senddata[]={"hello server!\n"};
    char recdata[100];
    write(sockfd,senddata,sizeof(senddata));
    int recvbitys = recv(sockfd,recdata,100,0);
    if((recvbitys) == -1){
        perror("rec error");
        exit(EXIT_FAILURE);
    }
    recdata[recvbitys] = '\0';
    printf("rec: %s",recdata);
    close(sockfd);
    return 0;
}