#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PWD_LEN 32

typedef unsigned int uint;
typedef struct UsrNode
{
   uint uiId;
   char caPwd[PWD_LEN];
   int sockfd;
   short iIsOnLine;
   struct UsrNode *pNext;
}UsrNode;

typedef struct UsrList
{
    uint uiLen;
    uint uiBaseId;
    UsrNode *pFirstNode;
}UsrList;


UsrNode *mkUsrNode();
UsrList *mkUsrList();
void insertUsrList(UsrList *list,UsrNode *node);
void display(const UsrList *list);
UsrNode *findById(uint uiId, const UsrList *list );




#endif