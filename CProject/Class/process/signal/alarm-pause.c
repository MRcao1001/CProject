#include "../public.h"
#include <signal.h>

void handle(int sig){
    if(SIGALRM == sig){
        printf("ararm is rining ...");
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    alarm(10);
    signal(SIGALRM,handle);
    pause();
    printf("stop pause!\n");

    return 0;
}
