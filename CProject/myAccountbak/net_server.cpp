#include "net_server.h"
#include <QDebug>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
using namespace std;
net_server::net_server()
{
}


int net_server::login_server(QString usr, QString pwd){
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1  == socketfd){
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9999);
    //servAddr.sin_addr.s_addr = inet_addr("193.112.137.246");
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(servAddr.sin_zero,8);

    if (connect(socketfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        {
            perror("connect");
            return -1;
        }
    int ret = -1;
    const char *caMsg = NULL;
    //字符转存
    QString str;
    str="L"+usr+"-"+pwd;
    QByteArray temp= str.toLatin1();
    caMsg = temp.data();
    qDebug()<<"net_server::login_server--->debug:"<<usr<<pwd<<caMsg;
    ret = send(socketfd,caMsg,strlen(caMsg),0);
    if(-1 == ret){
        perror("send");
        exit(EXIT_FAILURE);
    }
    char getMsg[16];//获取服务器发送的通知：true or false
    ret = recv(socketfd,getMsg,sizeof(caMsg),0);
    //写入session
    int retvalue = writeToSession(caMsg);
    qDebug()<<"net_server::login_server--->debug:获取writeToSession的返回值"<<retvalue;
    close((socketfd));
    if(strcmp(getMsg,"true") == 0){
        qDebug()<<"net_server::login_server--->debug:获取getMsg中的信息"<<"true";
        return 1;
    }
    else if(strcmp(getMsg,"false") == 0){
        qDebug()<<"net_server::login_server--->debug:获取getMsg中的信息"<<"false";
        return 0;
    }
    return 0;
}




int net_server::reg_server(QString usr, QString pwd, QString phone){
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1  == socketfd){
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9999);
    //servAddr.sin_addr.s_addr = inet_addr("193.112.137.246");
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(servAddr.sin_zero,8);

    if (connect(socketfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        {
            perror("connect");
            return 2;
        }
    int ret = -1;
    const char *caMsg = NULL;
    //字符转存
    QString str;
    str="R"+usr+"-"+pwd+"-"+phone;
    QByteArray temp= str.toLatin1();
    caMsg = temp.data();
    qDebug()<<"net_server::reg_server--->debug:"<<usr<<caMsg<<pwd;
    ret = send(socketfd,caMsg,strlen(caMsg),0);
    if(-1 == ret){
        perror("send");
        exit(EXIT_FAILURE);
    }
    char get_regMsg[16];
    ret = recv(socketfd,get_regMsg,sizeof(caMsg),0);
    qDebug()<<get_regMsg<<endl;
    close((socketfd));
    if(strcmp(get_regMsg,"YES") == 0){
        qDebug()<<"net_server::reg_server--->debug:"<<"YES";
        return 1;
    }
    else if(strcmp(get_regMsg,"NO") == 0){
        qDebug()<<"net_server::reg_server--->debug:"<<"NO";
        return 0;
    }
    else if(strcmp(get_regMsg,"beenreg") == 0){
        qDebug()<<"net_server::reg_server--->debug:"<<"beenreg";
        return 2;
    }
    return 0;
}


QString net_server::relogin(){

    //session文件读取到字符数组
    int fd_session = open("./session",O_RDONLY);
    if(-1 == fd_session){
        qDebug()<<"net_server::relogin--->debug:"<<"open file error";
        return 0;
    }
    char info[128] = {'\0'};
    int ret = 0;
    for(int i=0;i<128;i++){
        ret =read(fd_session,&info[i],1);
        if(info[i] == '\0'){
            break;
        }
        if(ret < 0){
            break;
        }
    }
    qDebug()<<"net_server::relogin--->debug:"<<info;
    close(fd_session);

    //字符数组分段拆解
    char userName_c[128] = {'\0'};
    char pwd_c[128] = {'\0'};
    int i = 1;
    for(i;i<128;i++){
        //写入是由函数writeTofile执行，写入的是login_server传入的整合字符，起始符为L，如果字符数组的起始符不是L证明之前执行了注销操作，将文件置空了；
        if(info[0] != 'L'){
            break;
        }
        if(info[i] == '-'){
            userName_c[i-1] = '\0';
            i=i+1;
            break;
        }
        userName_c[i-1] = info[i];
    }
    if(i < 2){
        qDebug()<<"net_server::relogin--->debug:"<<"文件字符长度<1，判断文件为空";
        return please_login;
    }
    int j = 0;
    for(i;i<128;i++){
        if(info[i] == '\0'){
            pwd_c[j] == '\0';
            break;
        }
        pwd_c[j] = info[i];
        j++;
    }
    qDebug()<<"net_server::relogin--->debug:"<<"username:"<<userName_c<<"pwd:"<<pwd_c;

    //拆解的字符串转换成Qstring
    QString userName(userName_c);
    QString pwd(pwd_c);
    int loginret = login_server(userName,pwd);
    qDebug()<<"net_server::relogin--->debug:获取loginserver的返回值"<<loginret;
    if(loginret == 1){
        return userName;
    }
    else if(loginret == -1){
        userName = "Internet_error";
        return userName;
    }
    else {
        userName = "请登录/注册";
        qDebug()<<"net_server::relogin--->debug:当用户名密码错误时返回的字符串是:"<<userName;
        return userName;
    }
}

//将登录、注册信息覆盖性写入到session
int net_server:: writeToSession(const char *session_get){
    qDebug()<<"net_server::writeToSession--->debug:"<<"准备写入session";
    int fd_session = open("./session",O_WRONLY|O_CREAT,0777);
    ssize_t ret = -1;
    if(-1 == fd_session){
        qDebug()<<"net_server::writeToSession--->debug:"<<"打开session失败";
        return 0;
    }
    else {
            /* 清空文件 */
            ftruncate(fd_session,0);
            /* 重新设置文件偏移量 */
            lseek(fd_session,0,SEEK_SET);

            ret = write(fd_session,session_get,128);
            if(-1 == ret){
                if(EINTR == errno){}
                else {
                    qDebug()<<"net_server::writeToSession--->debug:"<<"写入session失败";
                    close(fd_session);
                    return 0;
                }
            }
            else {
                qDebug()<<"net_server::writeToSession--->debug:"<<"写入session成功";
                close(fd_session);
                return 1;
            }
        }
    }

//清除session信息，实现退出登录
QString net_server::quitAccount(){
    qDebug()<<"net_server::quitAccount--->debug:"<<"正在清空session";
    int fd_session = open("./session",O_WRONLY);
    if(-1 == fd_session){
        qDebug()<<"net_server::writeToSession--->debug:"<<"打开session失败";
        return 0;
    }
    else {
            /* 清空文件 */
            ftruncate(fd_session,0);
            /* 重新设置文件偏移量 */
            lseek(fd_session,0,SEEK_SET);
            close(fd_session);
            QString ret = relogin();
            return ret;
        }

}

//显示treewidget的方法,传递链表
QList<QString> net_server::showTree_public_server(QString username_from_appdisplay){
    QList<QString> list1;
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1  == socketfd){
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9999);
    //servAddr.sin_addr.s_addr = inet_addr("193.112.137.246");
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(servAddr.sin_zero,8);

    if (connect(socketfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        {
            perror("connect");
            return list1;
        }
    int ret = -1;
    const char *caMsg = NULL;
    QString str;
    str="S"+username_from_appdisplay;
    QByteArray temp= str.toLatin1();
    caMsg = temp.data();
    //发送public、userName、userNameMsg
    qDebug()<<"net_server::show_tree_p_s--->debug:要返回"<<caMsg<<"的信息";
    ret = send(socketfd,caMsg,strlen(caMsg),0);
    if(-1 == ret){
        perror("send");
        return list1;
    }

//接收数据到客户端
    int i = 0;
    string pageName[100];
    for( i; i < 100 ; i ++){
        char getMsg[32] = {'\0'};
        ret = recv(socketfd,getMsg,sizeof(getMsg),0);
        send(socketfd,"OK",strlen(caMsg),0);
        pageName[i] = getMsg;
        if(pageName[i] == "#stop#"){
            break;
        }
    }
    i--;
    qDebug()<<"net_server::login_server--->debug:服务器传来了"<<i<<"条数据";
    for(i;i>=0;i--)
    {
        QString putMsg = QString::fromStdString (pageName[i]);
        list1<<putMsg;
    }
    close((socketfd));
    return list1;
}

QList<QString> net_server::showtable_server(){
    QList<QString> list1;
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1  == socketfd){
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9999);
    //servAddr.sin_addr.s_addr = inet_addr("193.112.137.246");
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bzero(servAddr.sin_zero,8);

    if (connect(socketfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
        {
            perror("connect");
            return list1;
        }
    int ret = -1;
    const char *caMsg = "Tpublic";
//    QString str;
//    str="T"+username_from_appdisplay;
//    QByteArray temp= str.toLatin1();
//    caMsg = temp.data();
    //发送public、userName、userNameMsg
    qDebug()<<"net_server::show_table_server--->debug:要返回"<<caMsg<<"的信息";
    ret = send(socketfd,caMsg,strlen(caMsg),0);
    if(-1 == ret){
        perror("send");
        return list1;
    }

//接收数据到客户端
    qDebug()<<"net_server::show_table_server--->debug:发送数据到客户端";
    int i = 0;
    for( i; i < 100 ; i ++){
        char getMsg[4096] = {'\0'};
        ret = recv(socketfd,getMsg,sizeof(getMsg),0);
        send(socketfd,"OK",strlen(caMsg),0);
        if(strcmp(getMsg,"#stop#") == 0){
            break;
        }

        list1 << QString::fromStdString (getMsg);
    }
    close((socketfd));
    return list1;
}

QString net_server::getClause(){
    qDebug()<<"net_server::getClause--->debug:"<<"star";
    int fd_session = open("./clause.txt",O_RDONLY);
    if(-1 == fd_session){
        qDebug()<<"net_server::relogin--->debug:"<<"open file error";
        return "null";
    }


    char info[41000] = {'\0'};
    int ret = 0;
    ret =read(fd_session,info,40960);
    QString str(info);
    qDebug()<<"net_server::getClause--->debug:"<<"end";
    return str;
}
