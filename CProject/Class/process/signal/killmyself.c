#include "../public.h"
#include <signal.h>

int main(int argc, char const *argv[])
{
    int i =0;
    while(1){
        printf("time-->%d\n",i+1);
        i++;
        sleep(1);
        if(5==i){
            kill(getpid(),SIGKILL);
        }
    }
    return 0;
}
