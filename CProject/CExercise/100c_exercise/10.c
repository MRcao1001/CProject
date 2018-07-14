#include <stdio.h>

int main(int argc, char const *argv[])
{

    printf("\n\n:)\n");
    for (int i = 0; i < 9; i++)
    {
        int num =0;
        while (num !=2)
        {
            for (int j = 0; j < i; j++)
            {
                printf("        ");
            }
            printf("████████████████\n");
            num++;
        }
        
    }
    return 0;
}
