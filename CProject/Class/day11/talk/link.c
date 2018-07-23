#include "link.h"

Node* mkNode()
{
	Node *node = (Node *)malloc(sizeof(Node));
	if (NULL == node)
	{
		printf("malloc node failed\n");
		exit(EXIT_FAILURE);
	}
	memset(node, 0, sizeof(Node));
	return node;
}

Link* mkLink()
{
	Link *link = (Link *)malloc(sizeof(Link));
	if (NULL == link)
	{
		printf("malloc link failed\n");
		exit(EXIT_FAILURE);
	}
	memset(link, 0, sizeof(Link));
	return link;
}

void insertLink(Link *link, Node *node)
{
	if (NULL != link && NULL != node)
	{
		node->next = link->pFirstNode;
		link->pFirstNode = node;
		link->iLen++;
	}
}
