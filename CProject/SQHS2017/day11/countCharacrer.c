#include<stdio.h>

int main(void)
{
    char arr[32] = "";
    int count[5] = {0};
    int i = 0;

    printf("input a string: ");
    //scanf("%s", arr);
    //gets(arr);    //有警告，不建议使用
    fgets(arr, 32, stdin);

    for(i=0; arr[i]!='\0'; i++)
    {
        if(arr[i]>='a' && arr[i]<='z')
            count[0]++;
        else if('A'<=arr[i] && arr[i]<='Z')
            count[1]++;
        else if('0'<=arr[i] && arr[i]<='9')
            count[2]++;
        else if(' ' == arr[i])
            count[3]++;
        else 
            count[4]++;
    }

    printf("小写:%d\n大写:%d\n数字:%d\n空格:%d\n其他:%d\n", count[0], count[1], count[2],count[3],count[4]);

    return 0;
}


