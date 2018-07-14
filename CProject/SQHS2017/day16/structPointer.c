#include<stdio.h>
#include<stdlib.h>  //malloc(), free()
#include<string.h>

typedef struct perInfo
{
    int age;
    char name[32];
    struct perInfo *pNext;
}PerInfo;

//宏定义结构体的大小
#define SIZE sizeof(PerInfo)

int main(void)
{
    system("clear");
    PerInfo *pStuOne = (PerInfo*)malloc(SIZE);
    pStuOne->age = 111;
    strcpy(pStuOne->name, "111");
    pStuOne->pNext = NULL;
    
    PerInfo *pStuTwo = (PerInfo*)malloc(SIZE);
    pStuTwo->age = 222;
    strcpy(pStuTwo->name, "222");
    //保存 pStuOne 指针所指向的地址
    pStuTwo->pNext = pStuOne;

    PerInfo *pStuThr = (PerInfo*)malloc(SIZE);
    pStuThr->age = 333;
    strcpy(pStuThr->name, "333");
    //保存 pStuTwo 指针所指向的地址
    pStuThr->pNext = pStuTwo;

    printf("p1 = %p\n", pStuOne);
    printf("p2 = %p\n", pStuTwo);
    printf("p3 = %p\n", pStuThr);

    printf("%d--%s--%p\n", pStuOne->age, pStuOne->name, pStuOne->pNext);
    printf("%d--%s--%p\n", pStuTwo->pNext->age, pStuTwo->pNext->name, pStuTwo->pNext->pNext);


    printf("%d--%s--%p\n", pStuTwo->age, pStuTwo->name, pStuTwo->pNext);
    printf("%d--%s--%p\n", pStuThr->pNext->age, pStuThr->pNext->name, pStuThr->pNext->pNext);
    
    
    printf("%d--%s--%p\n", pStuThr->age, pStuThr->name, pStuThr->pNext);

    puts("===============================");
    /*
        由上述赋值和打印结果可知:
            只要知道 pStuThr 的地址,就可以访问到
            pStuTwo 和 pStuOne, 因 pStuThr->pNext
            保存的是 pStuTwo 的地址, pStuThr->pNext
            保存的是 pStuOne 的地址
        重新定义一个指针指向 pStuThr ,然后我们利用
        该指针先访问 pStuThr,然后通过 pNext 指针去访问
        pStuTwo, 再通过 pStuTwo 的 pNext 的指针去访问
        pStuOne, pStuOne 的 pNext 为空,作为最终的结束条件
    */
    PerInfo *p = pStuThr;

    while(NULL != p)
    {
        printf("%d--%s--%p\n", p->age, p->name, p->pNext);
        //循环共经历两次,
        //第一次执行 p = pNext 后 p = pStuTwo, 
        //第二次执行 p = pNext 后 p = pStuOne
        p = p->pNext;  
    }

    //释放 malloc 申请的内存,防止内存泄漏
    free(pStuOne);
    free(pStuTwo);
    free(pStuThr);
    //置空,为了防止成为野指针
    pStuOne = NULL;
    pStuTwo = NULL;
    pStuThr = NULL;
    return 0;
}

