#include "link.h"

STU* mkStuNode()
{
	STU *node = (STU *)malloc(sizeof(STU));
	if (NULL == node)
	{
		printf("malloc stu node failed\n");
		exit(EXIT_FAILURE);
	}
	memset(node, 0, sizeof(STU));
	return node;
}

Link* mkStuLink()
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

void insertStuLink(Link *link, STU *node)
{
	if (NULL != link && NULL != node)
	{
		node->next = link->pFirstNode;
		link->pFirstNode = node;
		link->iLen++;
	}
}

void display(const Link *link)
{
	if (NULL != link)
	{
		STU *node = link->pFirstNode;
		while (NULL != node)
		{
			printf("id=%d, name=%s, score=%.2f\n"
				   , node->iId, node->caName
				   , node->fScore);
			node = node->next;
		}
	}
}

Link* destory(Link *link)
{
	if (NULL != link)
	{
		STU *node = NULL;
		while (1)
		{
			node = link->pFirstNode;
			if (NULL == node)
			{
				break;
			}
			link->pFirstNode = node->next;
			free(node);	
		}
		free(link);
	}
	return NULL;
}
