#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	alarm(5);

	int i = 0;
	while (1)
	{
		printf("time --> %d\n", ++i);
		sleep(1);
	}

	return 0;
}
