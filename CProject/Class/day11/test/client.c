#include "public.h"
#include  <sys/types.h>    //socket
#include <sys/socket.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr
#include "link.h"

int main(void)
{
	Link *link = mkStuLink();
	int i = 0;
	STU *node = NULL;
	for (; i<5; i++)
	{
		node = mkStuNode();
		printf("请输入id,name,score:\n");
		scanf("%d%s%f", &node->iId, node->caName, &node->fScore);
		insertStuLink(link, node);
	}

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

	node = link->pFirstNode;
	while (NULL != node)
	{
		write(sockfd, node, sizeof(STU));
		node = node->next;
	}

	//断开与服务器的连接
	close(sockfd);

	return 0;
}
