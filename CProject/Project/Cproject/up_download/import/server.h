#ifndef SERVER_H
#define SERVER_H

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
#include <pthread.h>
//变量声明
//全局socket变量
int socketfd;
//全局寄存数组
char arr[128];
//sockaddr_in 是internet环境下套接字的地址形式
struct sockaddr_in servAddr;
struct sockaddr_in clientAddr;
int clientSocketfd = -1;
int iLen;
//定义变量接收connect的返回值
int ret;
//定义变量获得键盘的返回值
int key;
//定义字符串变量存储路径信息
char getinfo[128] = {'\0'};

//声明stat结构体变量
struct stat pathGet;
//声明文件指针
int fd;
//定义指针返回文件名中第一个为'/'的位置
char *pFile;
pthread_t thr;

//函数声明
void connectToclient();
void *working(void *arg);
#endif