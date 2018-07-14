#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    /* code */
    int n =1;
    system("clear");
    printf("\n\n\n\n\t\t\t\t\t████████████████████████████████████████████████████████████████████\n");
    for(int i = 1; i <=32; i++){
        printf("\t\t\t\t\t██");
        for(int j = 0; j <8;j++){
            
            if(n%2==0){
                printf("\033[47;36m████████\033[0m");
                n++;
            }
            else{
                printf("        ");
                n++;
            }
        }
        if(i%4 == 0){
            n--;
        }
        printf("██\n");
    }
    printf("\t\t\t\t\t████████████████████████████████████████████████████████████████████\n");
    getchar();
    return 0;
}
