#include "../import/public.h"

//自定义函数连接到服务器
void connectToServer(){
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == socketfd){
        perror("初始化套接字出错");
        exit(EXIT_FAILURE);
    }

    //初始化套接字地址端口链接方式
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(8888);

    //置字节字符串前n个字节为零且包括‘\0’
    bzero(servAddr.sin_zero,8);

    ret = connect(socketfd, (struct sockaddr *)&servAddr, sizeof(servAddr) );
    if(-1 == ret){
        perror("连接失败");
        exit(EXIT_FAILURE);
    }
    printf("已连接\n");
}

//自定义函数选择功能'
void choise(){
    printf("您要使用上传功能还是下载功能呢?\n1:上传\t2:下载\n");
    scanf("%d",&key);
    switch(key){
        case 1:{
            upload();
        }
        case 2:{
            download();
        }
        default:{
            printf("您输入的好像不正确,请重新输入吧\n");
            break;
        }
    }
}