#include "../public.h"
#include <signal.h>

typedef void (*signhandler_t) (int);

void handle(int sig)
{
    if (SIGINT == sig)
    {
        printf("----------------------");
    }
}

int main(int argc, char const *argv[])
{
    signhandler_t prev = signal(SIGINT, handle);
    int i = 0;
    while (1)
    {
        printf(":)%d\n",++i);
        if(10 == i){
            signal(SIGINT,prev);
        }
        sleep(1);
    }
    return 0;
}
