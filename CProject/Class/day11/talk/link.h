#ifndef LINK_H
#define LINK_H

#include "public.h"

typedef struct Node
{
	int sockfd;
	struct Node *next;
}Node;

typedef struct Link
{
	Node *pFirstNode;
	int iLen;
}Link;

Node* mkNode();
Link* mkLink();
void insertLink(Link *link, Node *node);

#endif
