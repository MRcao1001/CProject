#include "public.h"
#include  <sys/types.h>    //socket
#include <sys/socket.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
	//监听客户端的连接
	//循环的查看是否有客户端要连接到服务器
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (-1 == sockfd)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(8888);
	servAddr.sin_addr.s_addr = INADDR_ANY;
	bzero(servAddr.sin_zero, 8);
	//将sockfd和要监听的ip及端口绑定
	//表示只监听从ip：127.0.0.1连接过来的和端口888对应的服务程序进行通信的客户端
	int ret = bind(sockfd
				   , (struct sockaddr*)&servAddr
				   , sizeof(servAddr));
	

	return 0;
}
