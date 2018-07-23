#include "public.h"
#include  <sys/types.h>    //socket
#include <sys/socket.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr

void *handleServer(void *arg)
{
	int sockfd = (int)arg;
	char caMsg[128] = {'\0'};
	ssize_t ret = -1;
	while (1)
	{
		memset(caMsg, 0, 128);
		ret = read(sockfd, caMsg, 128);
		if (0 == ret || -1 == ret)
		{
			break;
		}
		printf("recv msg --> %s\n", caMsg);
	}
}

char* getStrFromSTDIN(char *buf, int count)
{
	if (NULL == buf || count <= 0)
	{
		return NULL;
	}
	// "hello\n"
	// "1234567890\n"
	// "12345678901234567890\n"
	read(STDIN_FILENO, buf, count); //-->10
	char *p = strchr(buf, '\n');
	if (NULL != p)
	{
		*p = '\0'; 
	}
	else if (NULL == p)
	{
		while ('\n' != getchar())	
		{}
		buf[count-1] = '\0';
	}

	return buf;
}

int main(void)
{
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

	int ret = -1;
	ret = connect(sockfd
				  , (struct sockaddr*)&servAddr
			      , sizeof(servAddr));
	if (-1 == ret)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	printf("connect server ok\n");

	pthread_t thr;
	pthread_create(&thr, NULL, handleServer
				   , (void *)sockfd);


	char caMsg[128] = {'\0'};
	while (1)
	{
		printf("请输入要发送的信息:\n");
		getStrFromSTDIN(caMsg, sizeof(caMsg));
		write(sockfd, caMsg, strlen(caMsg));
		if (0 == strcmp("quit", caMsg))
		{
			break;
		}
	}

	//断开与服务器的连接
	close(sockfd);

	return 0;
}
