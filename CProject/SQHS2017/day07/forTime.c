#include<stdio.h>
#include<stdlib.h>  //sleep()
#include<unistd.h>  //system()

int main(void)
{
    int iHour = 23;
    int iMin  = 59;
    int iSec  = 50;

    for(;;)
    {
        if(iHour == 24)
            iHour = 0;
        for(; iMin<60; iMin++)
        {
            for(; iSec<60; iSec++)
            {
                system("clear");
                printf("%02d:%02d:%02d\n",
                      iHour, iMin, iSec);
                sleep(1);
            }
            iSec = 0;
        }
        iMin = 0;
        iHour++;
    }

    return 0;
}

