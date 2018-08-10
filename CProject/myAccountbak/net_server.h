#ifndef NET_SERVER_H
#define NET_SERVER_H

#include "./mywidget.h"
#include <sys/socket.h>

class net_server
{
public:
    net_server();
    int login_server(QString usr, QString pwd);
    int reg_server(QString usr, QString pwd, QString phone);
    QString relogin();
    QString quitAccount();
    int writeToSession(const char *session);
    QList<QString> showTree_public_server(QString username);
    QList<QString> showtable_server();
    QString getClause();
private:
    int socketfd;
    QString please_login = "请登录/注册";


};


#endif // NET_SERVER_H
