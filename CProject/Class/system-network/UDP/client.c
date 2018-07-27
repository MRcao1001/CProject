#include "public.h"
#include  <sys/types.h>    //socket
#include <sys/socket.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr
#include <sys/stat.h>
#include <fcntl.h>

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
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
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
	char caMsg[128] = {'\0'};
	while(1){
		printf("please input data:\n");
		getStrFromSTDIN(caMsg,128);
		if(0 == strcmp("quit",caMsg)){
			break;
		}
		ret = sendto(sockfd,
			caMsg,
			strlen(caMsg),
			0,
			(struct sockaddr*)&servAddr,
			sizeof(servAddr));
		if(-1 == ret){
			perror("send to ...\n");
			exit(EXIT_FAILURE);
		}
	}
	
	close(sockfd);

	return 0;
}
