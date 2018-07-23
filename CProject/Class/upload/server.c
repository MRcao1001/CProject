#include "public.h"
#include  <sys/types.h>    //socket
#include <sys/socket.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>

void* handleClient(void *arg)
{
	int sockfd = (int)arg;
	char caMsg[4096] = {'\0'};
	char caPath[128] = {'\0'};
	int fd = -1;
	int iSign = 0;
	int ret = -1;
	while (1)
	{
		printf("aaaa\n");
		if (0 == iSign)
		{
			memset(caPath, 0, 128);
			read(sockfd, caPath, sizeof(caPath));
			fd = open(caPath, O_WRONLY|O_CREAT
					  , 0664);
			printf("path --> %s\n", caPath);
			iSign = 1;
		}
		ret = read(sockfd, caMsg, sizeof(caMsg));
		if (0 == ret)
		{
			break;
		}
		else if (-1 == ret)
		{
			if (EINTR == ret)
			{
				continue;
			}
			break;
		}
		write(fd, caMsg, ret);
	}
	close(fd);

	return NULL;
}

int main(void)
{
	//监听客户端的连接
	//循环的查看是否有客户端要连接到服务器
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sockfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(8888);
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bzero(servAddr.sin_zero, 8);
	//将sockfd和要监听的ip及端口绑定
	//表示只监听从ip：127.0.0.1连接过来的和端口888对应的服务程序进行通信的客户端
	int ret = bind(sockfd
				   , (struct sockaddr*)&servAddr
				   , sizeof(servAddr));
	if (-1 == ret)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}

	//设置sockfd处理监听状态
	//并设置客户端连接队列的最大缓冲数
	ret = listen(sockfd, 20);
	if (-1 == ret)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in clientAddr;
	int clientSockfd = -1;
	int iLen = sizeof(clientAddr);
	char caMsg[64] = {'\0'};
	pthread_t thr;
	while (1)
	{
		//接收通过sockfd监听到的客户端的连接
		//并自动将客户端的相应信息填入clientAddr
		//连接成功则产生一个新的socket
		//用于客户端和服务器进行数据交互	
		printf("accepting client...\n");
		//如果没有连接，则阻塞等待
		clientSockfd = accept(sockfd
			, (struct sockaddr*)&clientAddr
			, &iLen);
		if (-1 == clientSockfd)
		{
			perror("accept");
			//continue;
			break;
		}
		//inet_ntoa:将整数表示的ip转变成点分十进制字符串表示
		printf("client ip:%s, port:%u connect ok  new sockfd = %d\n"
			   , inet_ntoa(clientAddr.sin_addr)
			   , clientAddr.sin_port
			   , clientSockfd);

		pthread_create(&thr, NULL, handleClient
					   , (void*)clientSockfd);
	}

	return 0;
}
