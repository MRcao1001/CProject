#ifndef LINK_H
#define LINK_H

#include "public.h"

typedef struct Student
{
	int iId;
	char caName[32];
	float fScore;
	struct Student *next;
}STU;

typedef struct Link
{
	STU *pFirstNode;
	int iLen;
}Link;

STU* mkStuNode();
Link* mkStuLink();
void insertStuLink(Link *link, STU *node);
void display(const Link *link);
Link* destory(Link *link);

#endif
