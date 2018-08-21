#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include  <sys/types.h>    //socket
#include <sys/socket.h>
#include <arpa/inet.h>     //htons
#include <netinet/in.h>    //inet_addr
#include <thread>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mysql/mysql.h>
#include <cstring>
//g++ main.cpp `mysql_config --cflags --libs` -o server -pthread
using namespace std;
//char username[],char password[]
typedef struct infor{
     char *author;
     char *pageName;
     char *pageType;
     char *pageDate;
     char *likes;
     char *diss;
     struct infor *pNext;
}info;

int login(char username[],char password[]){
    MYSQL conn;
    MYSQL_RES *mysql_result;
    MYSQL_ROW mysql_row;
    int f1,f2,num_row,num_col;
    char sql[128];

    sprintf(sql,"%s'%s'%s'%s'","select * from userInfo where userName=",username," and pwd=",password);
    //cout<<sql<<endl;
    int res = 0;
        mysql_init(&conn);
        if(mysql_real_connect(&conn,"localhost","admin","admin","yesterday",0,NULL,CLIENT_FOUND_ROWS)) //"root":数据库管理员 "":root密码 "test":数据库的名字
        {
            cout<<"-->[OK]已经连接到数据库!"<<endl;
            mysql_query(&conn,"set names 'GBK'");
            res=mysql_query(&conn,sql);
            if(res)
            {
                cout<<"-->[ER]查询语句有误,正在自检..."<<endl;
                return 1;
            }
            else
            {
                mysql_result=mysql_store_result(&conn);
                num_row=mysql_num_rows(mysql_result);
                num_col=mysql_num_fields(mysql_result);
                if(num_row > 0){
                    cout<<"-->[OK]数据匹配，正在返回结果..."<<endl;
                    return 0;
                }
                else {
                    cout<<"-->[ER]数据不匹配，正在返回结果..."<<endl;
                    return 1;
                }
//              输出查询到的所有数据，在显示界面会用到
//                printf("row: %d,col: %d\n",num_row,num_col);
//                   for(f1=0;f1<num_row;f1++)
//                      {
//                         mysql_row=mysql_fetch_row(mysql_result);

//                           for(f2=0;f2<num_col;f2++)
//                             {
//                               printf("[Row %d,Col %d]==>[%s]\n",f1,f2,mysql_row[f2]);

//                             }
//                      }
            }
            mysql_close(&conn);
        }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int reg(char username[],char password[],char phone[]){
    MYSQL conn;
    MYSQL_RES *mysql_result;
    MYSQL_ROW mysql_row;
    int f1,f2,num_row,num_col;
    char sql_reg[128];
    char sql_hasUser[128];
    char sql_add_table_for_user[128];
    char sql_add_table_for_userMsg[128];

    sprintf(sql_reg,"%s('%s','%s','%s')","insert into userInfo values",username,password,phone);
    sprintf(sql_hasUser,"%s'%s'","select * from userInfo where userName=",username);
    sprintf(sql_add_table_for_user,"%s %s%s","create table",username,"( pageName varchar(255), pageType longtext, pageDate varchar(32),likes int(10),diss int(10))");
    sprintf(sql_add_table_for_userMsg,"%s %s%s","create table",username,"Msg( sender varchar(255), mailTitle varchar(255), mail varchar(255))");
    //cout<<sql_reg<<endl;
    //cout<<sql_hasUser<<endl;
    cout<<sql_add_table_for_user<<endl<<sql_add_table_for_userMsg<<endl;
    int res = 0;
        mysql_init(&conn);
        if(mysql_real_connect(&conn,"localhost","admin","admin","yesterday",0,NULL,CLIENT_FOUND_ROWS)) //"root":数据库管理员 "":root密码 "test":数据库的名字
        {
            cout<<"-->[OK]已经连接到数据库!"<<endl;
            //判断用户名是否存在
            res=mysql_query(&conn,sql_hasUser);
            if(res)
            {
                cout<<"-->[ER]查询语句有误,正在自检..."<<endl;
                return 1;
            }
            else
            {
                mysql_result=mysql_store_result(&conn);
                num_row=mysql_num_rows(mysql_result);
                if(num_row > 0){
                    cout<<"-->[ER]用户已经注册，正在返回结果..."<<endl;
                    return 2;
                }
                else {
                    cout<<"-->[OK]用户未被注册，继续注册..."<<endl;
                }
            }
            //如果不存在执行注册
            res = 0;
            res=mysql_query(&conn,sql_reg);
            if(res)
            {
                cout<<"-->[ER]注册失败..."<<endl;
                return 1;
            }
            else
            {
                cout<<"-->[OK]注册成功"<<endl;
                res=mysql_query(&conn,sql_add_table_for_user);
                if(res)
                {
                    cout<<"-->[ER]添加用户表失败";
                    return 1;
                }
                else {
                    cout<<"-->[OK]添加用户表成功"<<endl;
                    res=mysql_query(&conn,sql_add_table_for_userMsg);{
                        if(res)
                        {
                            cout<<"-->[ER]添加用户邮件表失败";
                            return 1;
                        }
                        else {
                            cout<<"-->[OK]添加用户邮件表成功"<<endl;
                            cout<<"-->[OK]完成注册"<<endl;
                            return 0;
                        }
                    }
                }
            }
            mysql_close(&conn);
        }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
info *makeNode()
{
    info *newNode = (info*)malloc(sizeof(info));
    if(NULL == newNode)
        newNode = (info*)malloc(sizeof(info));
    newNode->pNext = NULL;
    return newNode;
}
info *search(char tablename[]){

    //创建链表节点
    info *headNode = makeNode();

    MYSQL conn;
    MYSQL_RES *mysql_result;
    MYSQL_ROW mysql_row;
    int f1,f2,num_row,num_col;
    char sql[128];
    /*,tablename*/
    sprintf(sql,"%s%s","select * from ",tablename);
    //cout<<sql<<endl;
    int res = 0;
        mysql_init(&conn);
        if(mysql_real_connect(&conn,"localhost","admin","admin","yesterday",0,NULL,CLIENT_FOUND_ROWS)) //"root":数据库管理员 "":root密码 "test":数据库的名字
        {
            cout<<"-->[OK]已经连接到数据库!"<<endl;
            mysql_query(&conn,"set names 'UTF8'");
            res=mysql_query(&conn,sql);
            if(res)
            {
                cout<<"-->[ER]查询语句有误,正在自检..."<<endl;
                return NULL;
            }
            else
            {
                mysql_result=mysql_store_result(&conn);
                num_row=mysql_num_rows(mysql_result);
                num_col=mysql_num_fields(mysql_result);
//              输出查询到的所有数据，在显示界面会用到
                printf("row: %d,col: %d\n",num_row,num_col);
                   for(f1=0;f1<num_row;f1++)
                      {
                       info *newnode = makeNode();
                         mysql_row=mysql_fetch_row(mysql_result);

                           for(f2=0;f2<num_col;f2++)
                             {
                               printf("[Row %d,Col %d]==>[%s]\n",f1,f2,mysql_row[f2]);

                             }
                         newnode->author =  mysql_row[0];
                         newnode->pageName = mysql_row[1];
                         newnode->pageType = mysql_row[2];
                         cout<<newnode->pageType<<endl;
                         newnode->pageDate = mysql_row[3];
                         newnode->likes = mysql_row[4];
                         newnode->diss = mysql_row[5];

                         newnode->pNext = headNode->pNext;
                         headNode->pNext = newnode;
                         newnode = NULL;
                      }
            }
            mysql_close(&conn);
        }
        return headNode;
}
void* star_a_work(void *arg){

    int clientSocketfd = *(int*)arg;
    char caMsg[128];
    memset(caMsg, 0, sizeof(caMsg));
    int ret = recv(clientSocketfd,caMsg,sizeof(caMsg),0);
    if(0 == ret){
        perror("---[ER]recv");
        return 0;
    }
    if(-1 == ret){
        if(EINTR == ret){
            return 0;
        }
        perror("---[ER]recv");
        return 0;
    }

/////////////////////////////////////////登录//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    char username[64];
    char password[12];
    if(caMsg[0] == 'L'){
        //分离字符串
        int i =1;
        int j =0;
        for(i;i <128; i++){
            if(caMsg[i] == '-'){
                j=0;
                i++;
                break;
            }
            else if(caMsg[i]=='\0'){
                cout<<"---[ER]密码信息丢失"<<endl;
                break;
            }
            username[j]=caMsg[i];
            j++;
        }
        for(i;i<128;i++){
            if(caMsg[i]=='\0'){
                break;
            }
            password[j]=caMsg[i];
            j++;
        }
        cout<<"---[OK]传来的用户名："<<username<<"     传来的密码："<<password<<endl;
        //判断用户名密码
        int ret = login(username,password);
        if(ret == 0){
            cout<<"---[OK]用户名和密码正确，正在通知客户端"<<endl;
            send(clientSocketfd,"true",sizeof(caMsg),0);
            return 0;
        }
        else if(ret == 1) {
            cout<<"---[ER]用户名和密码错误，正在通知客户端...已完成"<<endl;
            send(clientSocketfd,"false",sizeof(caMsg),0);
            return 0;
        }
        else {
            cout<<"---[ER]发生错误"<<endl;
            return 0;
        }
    }
 /////////////////////////////////////////注册/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    char reg_username[64];
    char reg_password[12];
    char reg_phone[11];
    if(caMsg[0] == 'R'){
        //分离字符串
        int i =1;
        int j =0;
        for(i;i <128; i++){
            if(caMsg[i] == '-'){
                j=0;
                i++;
                break;
            }
            else if(caMsg[i]=='\0'){
                cout<<"---[ER]密码信息丢失"<<endl;
                break;
            }
            reg_username[j]=caMsg[i];
            j++;
        }
        for(i;i<128;i++){
            if(caMsg[i] == '-'){
                j=0;
                i++;
                break;
            }
            if(caMsg[i]=='\0'){
                cout<<"---[ER]手机号信息丢失"<<endl;
                break;
            }
            reg_password[j]=caMsg[i];
            j++;
        }
        for(i;i<128;i++){
            if(caMsg[i]=='\0'){
                break;
            }
            reg_phone[j]=caMsg[i];
            j++;
        }
        cout<<"---[OK]传来的用户名："<<reg_username<<"     传来的密码："<<reg_password<<"     传来的手机号："<<reg_phone<<endl;
        //判断用户名密码
        int ret = reg(reg_username,reg_password,reg_phone);
        if(ret == 0){
            cout<<"---[OK]成功注册，正在通知客户端"<<endl;
            send(clientSocketfd,"YES",sizeof(caMsg),0);
            return 0;
        }
        else if(ret == 1) {
            cout<<"---[ER]注册失败，正在通知客户端"<<endl;
            send(clientSocketfd,"NO",sizeof(caMsg),0);
            return 0;
        }
        else if(ret == 2){
            cout<<"---[ER]用户已经被注册"<<endl;
            send(clientSocketfd,"beenreg",sizeof(caMsg),0);
            return 0;
        }
        else{
            return 0;
        }
    }

/////////////////////////////////////显示信息到左侧列表///////////////////////////////////////////////////////
    char show_username[64];
    if(caMsg[0] == 'S'){
        for(int i = 1;i<128;i++){
            if(caMsg[i] == '\0'){
                break;
            }
            show_username[i-1] = caMsg[i];
        }
        cout<<"[OK]传来的请求是:"<<show_username<<endl;
        info *pHead_temp = search(show_username);
        cout<<"[OK]获取到了返回值:"<<endl;
        info *p = pHead_temp->pNext;
        char getrecive[16];
        if(strcmp(show_username,"public") ==0){
            while(NULL != p){
                ret = send(clientSocketfd,p->pageName,sizeof(p->pageName),0);
                recv(clientSocketfd,getrecive,sizeof(getrecive),0);
                cout<<p->pageName<<endl;
                cout<<getrecive<<endl;
                p = p->pNext;
            }
        }
        else {
            while(NULL != p){
                ret = send(clientSocketfd,p->author,sizeof(p->author),0);
                recv(clientSocketfd,getrecive,sizeof(getrecive),0);
                cout<<p->author<<endl;
                cout<<getrecive<<endl;
                p = p->pNext;
            }
        }
        send(clientSocketfd,"#stop#",sizeof(p->pageName),0);
        cout<<"服务器处理查询结束"<<endl;
        return 0;
    }
/////////////////////////////////////填充信息到中间表格///////////////////////////////////////////////////////
        char table_username[64];
        if(caMsg[0] == 'T'){
            for(int i = 1;i<128;i++){
                if(caMsg[i] == '\0'){
                    break;
                }
                table_username[i-1] = caMsg[i];
            }
            cout<<"[OK]传来的请求是:"<<table_username<<endl;
            info *pHead_temp = search(table_username);
            cout<<"[OK]获取到了返回值:"<<endl;

            info *p = pHead_temp->pNext;
            cout<<"text的长度为:"<<sizeof(p->pageType);
                while(NULL != p){
                    string temp = string(p->author)+"#"+string(p->pageName)+"#"+string(p->pageDate)+"#"+string(p->pageType)+"#"+string(p->likes)+"#"+string(p->diss)+"E";
                    const char *result=temp.c_str();
                    ret = send(clientSocketfd,result,4096,0);
                    cout<<result<<endl;
                    p = p->pNext;
                }

            send(clientSocketfd,"#stop#",sizeof(p->pageName),0);
            string str = "我爱你";
            cout<<"服务器处理查询结束"<<endl;
            return 0;
        }
    cout<<"服务器处理结束"<<endl;
    return 0;
}


int main()
{
    int socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == socketfd){
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9999);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(servAddr.sin_zero,8);

    // 设置套接字选项避免地址使用错误
    int on=1;
    if((setsockopt(socketfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)))<0)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    int ret = bind(socketfd, (struct sockaddr *)&servAddr,sizeof(servAddr));
    if(-1 == ret){
        perror("bind");
        exit(EXIT_FAILURE);
    }

    ret = listen(socketfd,20);
    if(-1 == ret){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in clientAddr;
    int clientSocketfd;
    socklen_t iLen= sizeof(clientAddr);

    pthread_t addthread;
    char caMsg[1024];
    while (1) {
        cout<<endl<<endl<<"[WT]wating cilent connect ..."<<endl<<endl;
        clientSocketfd = accept(socketfd,(struct sockaddr*)&clientAddr,&iLen);

        if(-1 == clientSocketfd){
            cout<<"error of accept"<<endl;
            continue;
        }
        printf("\n[OK]收到来自ip为:%s, 端口为:%u的请求,new sockfd = %d\n"
                       , inet_ntoa(clientAddr.sin_addr)
                       , clientAddr.sin_port
                       , clientSocketfd);
        pthread_create(&addthread,NULL,star_a_work,&clientSocketfd);

    }
    return 0;
}
