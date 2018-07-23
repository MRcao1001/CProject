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

	char caPath[128] = {'\0'};
	struct stat buf;
	while (1)
	{
		printf("请输入要上传文件的路径:\n");
		//getStrFromSTDIN(caPath, sizeof(caPath));
		scanf("%s", caPath);
		if (-1 == stat(caPath, &buf))
		{
			perror("stat");
			continue;
		}
		if (S_ISREG(buf.st_mode))
		{
			break;
		}
		else
		{
			printf("您要上传的不是一个常规文件\n");
		}
	}

	int fd = open(caPath, O_RDONLY);
	if (-1 == fd)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	//home/wtp/car.c
	//    car.c
	//从路径中提取文件名字
	char *p = strrchr(caPath, '/');
	//将文件名字发送过去
	if (NULL != p)
	{
		p++;
	}
	else
	{
		p = caPath;
	}
	printf("path:%s\n", p);
	write(sockfd, p, strlen(p));
	sleep(1);
	char caMsg[4096] = {'\0'};
	while (1)
	{
		ret = read(fd, caMsg, sizeof(caMsg));
		if (0 == ret)
		{
			break;
		}	
		if (-1 == ret)
		{
			if (EINTR == ret)
			{
				continue;
			}
			perror("upload failed");
			break;
		}
		write(sockfd, caMsg, ret);
	}

	close(fd);
	//断开与服务器的连接
	close(sockfd);

	return 0;
}
