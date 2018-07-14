#include<stdio.h>

int main(void)
{
    int i = 3;
    int j = 5;

    const int *pi = &i;     //*pi 不可更改,pi 可更改
    //int const *pi = &i;

    int * const pj = &j;    //pj 不可更改, *pj 可更改

    const int * const p = &i;// *p 和 p 都不能改变

    //printf("*pi = %d\n", *pi);
    printf("*pj = %d\n", *pj);
    //i += 3;
    *pj += 3;
    //pj = &i;  //pj 是只读,pj 的值不能更改
    
    //*pi += 3;     //*pi 是只读
    //pi = &j;
    

    printf("i = %d\n", i); 
    printf("j = %d\n", j);
    printf("*pi = %d\n", *pi);
    printf("*pj = %d\n", *pj);

    return 0;
}

