#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h> 

typedef struct Node{
    long stuNum;
    int age;
    int gread; 
}Node;

typedef struct Stu{
    struct Node data;
    struct Stu *pNext;
}Stu;

//创建节点
Stu *makeNode(){
    Stu *newstu = (Stu *)malloc(sizeof (Stu));
    if(NULL == newstu){
        Stu *newstu = (Stu *)malloc(sizeof (Stu));
    }
    newstu->pNext=NULL;
    return newstu;
    
}
//录入数据
void pushData(long stuNum, int age, int gread, Node *node){
    
        //数据录入
        node->stuNum = stuNum;
        node->age = age;
        node->gread = gread;
}
int addData(Stu *pHead, Node data){
    if(NULL==pHead){
        printf("this linklist is empty");
        return -1;
    }
    Stu *newstu = makeNode();
    newstu ->data = data;
    newstu->pNext = pHead->pNext;
    pHead->pNext = newstu;
    newstu = NULL;
    return 0;
}


//文件写入操作
int writeToFile(Stu *pHead){
    int fd = open("/home/mrcao/test.txt",O_RDWR);
    Stu *temp = pHead->pNext;
    ssize_t ret = -1;
    if(-1 == fd){
        perror("open file");
        exit(EXIT_FAILURE);
    }
    else{
        printf("success open\n");
        while(NULL != temp){
            ret = write(fd, &temp->data, sizeof(Node));
            temp = temp->pNext;
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
    close(fd);
    return 0;

}
//文件读取
int readFromFile(){
    int fd = open("/home/mrcao/test.txt",O_RDWR);
    if(-1 == fd){
        perror("open file");
        exit(EXIT_FAILURE);
    }
    Stu *temp =makeNode();
    int ret = read(fd, &temp->data,sizeof(Node));
    if(ret >=0 ){
        while(NULL != temp){
            printf("存入文件之后再读取：\n%ld\t%d\t%d\n",temp->data.stuNum,temp->data.age,temp->data.gread);
            temp=temp->pNext;
        }
    }
    else{
        printf("error");
    }
    close(fd);
    return 0;
}


int main(int argc, char const *argv[]){
    Stu *pHead = makeNode();
    Node data;
    memset(&data, '\0', sizeof(Node));
    long stuNum;
    int age;
    int gread;

    scanf("%ld",&stuNum);
    getchar();
    scanf("%d",&age);
    getchar();
    scanf("%d",&gread);
    getchar();

    pushData(stuNum,age,gread, &data);
    addData(pHead,data);

    Stu *p = pHead->pNext;
    while(NULL != p){
        printf("直接从链表输出：\n%ld\t%d\t%d\n",p->data.stuNum,p->data.age,p->data.gread);
        p=p->pNext;
    }

    writeToFile(pHead);
    readFromFile();
    return 0;
}
