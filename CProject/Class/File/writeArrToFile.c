#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h> 


int main(int argc, char const *argv[])
{
    //创建学生二位数组
    char stu[5][32]={
        {"name:caoyong;age:21"},
        {"name:chenfei;age:23"},
        {"name:chenhao;age:23"},
        {"name:sunsicheng;age:22"},
        {"name:yangxiaoguo;age:21"},
    };
    //文件写入
    int fd_write = open("/home/mrcao/test.txt",O_WRONLY);
    ssize_t ret = -1;
    if(-1 == fd_write){
        perror("open file");
        exit(EXIT_FAILURE);
    }
    else{
        printf("success open\n");
        for(int i = 0; i < 5; i ++){
            ret = write(fd_write, &stu[i], 32);
            sleep(1);
            if (-1 == ret){
                    if (EINTR == errno){}
                    else{
                        perror("write");
                    }
                }
            else{
                    printf("已经将 %ld 字节数据写入文件\n", ret);
                }
        }
        
    }
    close(fd_write);

    //问价读取
    int fd_read = open("/home/mrcao/test.txt",O_RDONLY);
    if(-1 == fd_read){
        perror("open file");
        exit(EXIT_FAILURE);
    }
    char getstu[5][32] ={};
    for(int i=0 ; i < 5; i ++){
        int ret = read(fd_read, &getstu[i],32);
        lseek(fd_read,32,SEEK_CUR);//指针向后移动32字节然后继续读取
    }
    
    if(ret >=0 ){
        for(int i = 0; i  <5; i ++){
            printf("%s\n",getstu[i]);
        }
    }
    else{
        printf("error");
    }
    close(fd_read);


    return 0;
}
