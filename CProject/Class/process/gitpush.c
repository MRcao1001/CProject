#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    pid_t pid =  fork();
    if(pid > 0 ){
        wait(NULL);
        pid_t pid2 =fork();
        if(pid2>0){
            wait(NULL);
            pid_t pid3 = fork();
            if(pid3>0){
                wait(NULL);
                printf("push success!");
            }






            else if(pid3 == 0) {
                system("git push -u orgin master");
            }
            else{
                perror("fork");
            }    
        }






        else if(pid2 == 0){
            system("git commit -m '全自动提交'");
        }
        else{
            perror("fork");
        }
    }







    else if(pid == 0){
        system("git add CProject");
    }
    else{
        perror("fork");
    }
    return 0;
}
