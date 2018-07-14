#ifndef _ADMIN_H_
#define _ADMIN_H_

#include"./list.h"

enum AdminFunc
{
    EXIT_ADMIN,
    ADD_USER,
    DELETE_USER,
    UPDATE_USER,
    LOOKUP_USER
};

void mainMenu(userNode *);
int adminFunc(userNode *);





#endif
