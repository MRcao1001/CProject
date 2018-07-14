#include<stdio.h>
#include<string.h>

typedef struct person
{
    int age;
    char name[32];
}Person;

int main(void)
{
    Person boy1 = {22, "Jack"};
    Person boy2;
    
    //内存块的拷贝
    memcpy(&boy2, &boy1, sizeof(boy1));
    //memcmp()  //内存块的比较

    FILE *fp = fopen("per.txt", "w+");
    if(NULL == fp)
    {
        perror("fp NULL");
        return -1;
    }

    fwrite(&boy1, sizeof(boy1), 1, fp);
    fwrite(&boy2, sizeof(boy2), 1, fp);

    rewind(fp);

    memset(&boy1, '\0', sizeof(boy1));
    memset(&boy2, '\0', sizeof(boy2));

    fread(&boy1, sizeof(boy1), 1, fp);
    fread(&boy2, sizeof(boy2), 1, fp);

    printf("boy1:%d--%s\n",boy1.age, boy1.name);
    printf("boy2:%d--%s\n",boy2.age, boy2.name);

    fclose(fp);
    return 0;
}




