#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Test
{
    int iData;
    double lfData;
    char caData[32];
    char caBuf[4];
}Test;

int main (void)
{
   Test *test = (Test *)malloc(1024);
   test->iData=189;
   test->lfData = 3.14;
   strcpy(test->caData,"hello world");
   strcpy(test->caBuf,"窗前明月光，疑是地上霜.");
   printf("iData=%d,lfData=%lf,caData=%s,caBuf=%s\n",
  test->iData,test->lfData,test->caData,test->caBuf);


    return 0 ;
}