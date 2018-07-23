#include "public.h"
#include  <sys/types.h>    //socket
#include <sys/socket.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr
#include "link.h"
#include <pthread.h>

void* handleClient(void *arg)
{
	int sockfd = (int)arg;
	Link *link = mkStuLink();
	STU *node = NULL;
	while (1)
	{
		node = mkStuNode();
		//若对方连接断开，read返回值为0
		if (0 == read(sockfd, node, sizeof(STU)))
		{
			free(node);
			break;
		}
		insertStuLink(link, node);
	}
	display(link);
	//link = destory(link);

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
