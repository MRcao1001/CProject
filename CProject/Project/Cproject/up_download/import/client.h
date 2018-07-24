#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>//htons
#include <netinet/in.h>//inet_addr
#include <sys/stat.h>
#include <fcntl.h>

//变量声明
//全局socket变量
int socketfd;
//全局寄存数组
char arr[128];
//sockaddr_in 是internet环境下套接字的地址形式
struct sockaddr_in servAddr;
//定义变量接收connect的返回值
int ret;
//定义变量获得键盘的返回值
int key;
//定义字符串变量存储路径信息
char path[128] = {'\0'};
//声明stat结构体变量
struct stat pathGet;
//声明文件指针
int fd;
//定义指针返回文件名中第一个为'/'的位置
char *pFile;
//定义文件寄存数组
char fileArr[4096]= {'\0'};

//函数声明
//连接服务器函数
void connectToServer();
//选择功能函数
void choise();
//上传函数
void upload();
//下载函数
void download();

#endif