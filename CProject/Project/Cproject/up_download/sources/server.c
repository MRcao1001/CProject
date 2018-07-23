#include "../import/server.h"


void *working(void *arg){
    int socket = (int)arg;
    char fileArr[4096] = {'\0'};
    char path [128] = {'\0'};
    int fd = -1;
    int iSign = 0;
    int ret = -1;
    int tmp = 0;
    while(1){
        if(0 == iSign){
            memset(path, 0 ,128);
            strcpy(path,"../FTP/");
            tmp = strlen(path);
            read(socket,path+tmp,sizeof(path)-tmp);
            fd = open(path,O_WRONLY|O_CREAT,0777);
            printf("准备向%s中复制文件...\n",path);
            iSign = 1;
        }
        ret = read(socket,fileArr,sizeof(fileArr));
        if(0 == ret){
            break;
        }
        else if (-1 == ret){
            if(EINTR == ret){
                continue;
            }
            break;
        }
        write(fd,fileArr,ret);
    }
    printf("复制已经完成...\n",path);
    close(fd);
    return NULL;
}
//////////////////////////////////////////////////////////////////////
void connectToclient(){
    socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == socketfd){
        perror("创建连接环境失败");
        exit(EXIT_FAILURE);
    }

    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8888);
    bzero(servAddr.sin_zero,8);
    int on=1;  
    if((setsockopt(socketfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on)))<0)  
    {  
        perror("setsockopt failed");  
        exit(EXIT_FAILURE);  
    }
    ret = bind(socketfd, (struct sockaddr*)&servAddr,sizeof(servAddr));
    if(-1 == ret){
        perror("与客户端失联");
        exit(EXIT_FAILURE);
    }

    //设置socket处理监听状态
    //设置客户端连接队列的最大缓冲数量
    ret = listen(socketfd,20);
    if(-1 == ret){
        perror("监听出现故障");
        exit(EXIT_FAILURE);
    }
    clientSocketfd = -1;
    iLen = sizeof(clientAddr);

    while(1){
        //接收通过socket监听到的客户端连接
        //并自动将客户端的相应信息填入clientAddr
        //连接成功就生成一个新的socket
        printf("等待客户端响应...\n");
        clientSocketfd = accept(socketfd, (struct  sockaddr*)&clientAddr,&iLen);
        if(-1 == clientSocketfd){
            perror("连接出现问题");
            break;
        }
        printf("client ip:%s, port:%u connect ok  new sockfd = %d\n"
			   , inet_ntoa(clientAddr.sin_addr)
			   , clientAddr.sin_port
			   , clientSocketfd);
        //创建一个新线程处理连接成功的客户端的进一步请求
        pthread_create(&thr,NULL,working,(void *)clientSocketfd);
    }
    
}
///////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{
    connectToclient();
    return 0;
}
