/*
 * @Author: MRcao on ubuntu18.04
 * @Date: 2018-08-01 15:38:36
 * @LastEditors: MRcao
 * @LastEditTime: 2018-08-01 15:45:07
 * @Description: 
 */
#include <iostream>
#include <string>

using namespace std;

main(int argc, char const *argv[])
{
    /* code */
    int *p0 = (int *)malloc(sizeof(int));
    int *p1 = new int(9990);
    //如果调用上述结构时使用malloc不会自动初始化和调用构造函数，而使用new会在申请空间的同时初始化和调用构造函数；
    return 0;
}
