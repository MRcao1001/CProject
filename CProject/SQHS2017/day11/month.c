#include<stdio.h>

int main(void)
{
	char *pMon[13] = {
					   "illeagal", "January",
					   "February", "March", "April",
					   "May", "June", "July",
					   "August",    "September",
					   "October", "November",
					   "December"
					 };
	int month = 0;
	
	printf("input a month[1-12]: ");
	scanf("%d", &month);
	getchar();
	
	if(month > 0 && month < 13)
	{
		printf("%s\n", *(pMon+month));
		printf("%s\n", pMon[month]);
	}
	else
	{
		printf("%s\n", pMon[0]);
	}
	
	
	
	return 0;
}











