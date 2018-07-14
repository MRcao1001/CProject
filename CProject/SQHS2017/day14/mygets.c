#include<stdio.h>

char *mygets(char *dest, int len)
{
    char *pa = dest; 

    //减一是为了当输入大于等于len时
    //空出一位来存放 '\0'
    for(pa=dest; pa<dest+len-1; pa++)
    {
        *pa = getchar();
        if('\n' == *pa)
            break;
    }

    //当输入长度大于 len-1 时,要吸收多余的
    //输入字符,当碰到 '\n' 时输入结束
    if('\n' != *pa)
        while('\n' != getchar());
    
    //在输入的数据末尾添加字符串的结束标志 '\0'
    *pa = '\0';
    return dest;
}

