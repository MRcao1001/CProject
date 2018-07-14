#include "public.h"
//遗留问题：自己输入数据会产生几个乱码；无法插入，只能覆盖输入
char mygetch()
{
    char c;
    system("stty -echo");
    system("stty -icanon");
    c=getchar();
    system("stty icanon");
    system("stty echo");
    return c;
}

int main(int argc, char const *argv[])
{
    int fd = open("/home/mrcao/test.txt",O_RDWR);
    if (-1 == fd)
    {
        perror("open file");
    	exit(EXIT_FAILURE);
    }

    
    char arr[5][32]={};
    
    for(int i = 0; i < 4; i ++){
        int ret = read(fd,&arr[i],32);
        printf("%s\n",arr[i]);
    }
    int position = 0;
    printf("\n您想从第几个字符后面插入新内容呢：");
    scanf("%d",&position);
    getchar();
    lseek(fd,position,SEEK_SET);
    char buf[32];
    printf("请输入内容：");
    int help=0;
    for(int i = 0; i < 32 ; i ++){
        char p = getchar();
        if(p != '\n'){
            buf[i] = p;
            help ++;
            continue;
        }
        break;
    }
    int ret2=write(fd,&buf,32);
    if (-1 == ret2){
        if (EINTR == errno){}
        else{
            perror("write");
        }
    }
    else{
        printf("从第%d个字符开始替换了 %d 个字符\n",position, ret2);
    }
    printf("插入的可见字符串是：");
    for(int i = 0 ; i < help; i ++){
        if(buf[i]!= '\n'){
            
            printf("%c",buf[i]);
            continue;
        }
        break;
    }
    return 0;
}
