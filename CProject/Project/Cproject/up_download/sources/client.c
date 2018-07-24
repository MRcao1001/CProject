#include "../import/client.h"

/******************声明*******************
/网络服务器地址 193.112.137.246 root@debian  
/本机地址 127.0.0.1                       
/****************************************/

//自定义函数连接到服务器/////////////////////////////////////////////////
void connectToServer()
{
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == socketfd)
    {
        perror("初始化套接字出错");
        exit(EXIT_FAILURE);
    }

    //初始化套接字地址端口链接方式
    servAddr.sin_addr.s_addr = inet_addr("193.112.137.246");
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(8888);

    //置字节字符串前n个字节为零且包括‘\0’
    bzero(servAddr.sin_zero, 8);

    ret = connect(socketfd, (struct sockaddr *)&servAddr, sizeof(servAddr));
    if (-1 == ret)
    {
        perror("连接失败");
        exit(EXIT_FAILURE);
    }
    printf("已连接\n");
}

//自定义函数选择功能//////////////////////////////////////////////////////////
void choise()
{
    while (1)
    {
        printf("您要使用上传功能还是下载功能呢?\n1:上传\t2:下载\t3:取消\n");
        scanf("%d", &key);
        switch (key)
        {
            case 1:
            {
                upload();
            }
            case 2:
            {
                download();
            }
            case 3:
            {
                exit(0);
            }
            default:
            {
                printf("您输入的好像不正确,请重新输入吧\n");
                continue;
            }
        }
    }
    
}

//上传文件功能//////////////////////////////////////////////////////////
void upload()
{
    while (1)
    {
        printf("请输入上传文件的路径,结尾不要加上'/'\n");
        scanf("%s", path);
        if (-1 == stat(path, &pathGet))
        {
            perror("访问路径出错");
            continue;
        }
        if (S_ISREG(pathGet.st_mode))
        {
            break;
        }
        else
        {
            printf("您选择的不是文件,请重试\n\n");
        }
    }

    fd = open(path, O_RDONLY);
    if (-1 == fd)
    {
        perror("打开文件失败,程序已结束");
        exit(EXIT_FAILURE);
    }

    //从路径中提取文字,反向遍历数组
    pFile = strrchr(path, '/');

    //传送文件名到服务器
    if (NULL != pFile)
    {
        pFile++;
    }
    else
    {
        pFile = path;
    }

    printf("文件%s正在上传,请稍后\n", pFile);
    write(socketfd, pFile, strlen(pFile));
    sleep(1);

    while (1)
    {
        //文件内容读取到数组fileArr中
        ret = read(fd, fileArr, sizeof(fileArr));
        if (0 == ret)
        {
            break;
        }
        if (-1 == ret)
        {
            if (EINTR == ret)
            {
                continue;
            }
            perror("上传失败");
            break;
        }
        //数组fileArr中数据写入到socket中
        write(socketfd, fileArr, ret);
    }

    close(fd);
}

/////////////////////////////////////////////////////////////////
void download(){
    //接收服务器发来的所有文件名
    
    //发送要下载的文件名
    //客户端接收服务器发送过来的文件数据

}

////////////////////////////////////////////////////////////////////
int main(int argc, char const *argv[])
{
    //调用函数连接到服务器
    connectToServer();
    choise();
    close(socketfd);
    return 0;
}
