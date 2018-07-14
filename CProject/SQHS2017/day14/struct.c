#include<stdio.h>

//不占据空间,只是说明一种数据类型
struct point
{
    float x;
    float y;
}a;

int main(void)
{
    a.x = 3;
    a.y = 4;
    
    printf("%g--%g\n", a.x, a.y);

    return 0;
}

