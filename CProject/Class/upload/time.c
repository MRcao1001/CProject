#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

#define NUM 100000

void myswap(int *p,int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void dubbleSort(int arr[NUM])
{
	int i = 0;
	int j = 0;
	for(i = 0;i<NUM-1;i++)
	{
		for(j = NUM-1;j>i;j--)
		{
			if(arr[j]<arr[j-1])
			{
				myswap(arr+j,arr+(j-1));
			}
		}
	}
}

void selectSort(int arr[NUM])
{
	int i = 0;
	int j = 0;
	int min = 0;
	int tmp = 0;
	for(i=0;i<NUM;i++)
	{
		min = i;
		for(j=i+1;j<NUM;j++)
		{
			if(arr[j]<arr[min])
			{
				{
					min = j;
				}
				if(min!=i)
				{
					tmp = arr[j];
					arr[j] = arr[min];
					arr[min] = tmp;
				}
			}
		}
	}
}

void insertSort(int arr[NUM])
{
	int i = 0;
	int p = 0;
	int tmp = 0;
	for(i=0;i<NUM;i++)
	{
		p = i-1;
		tmp = arr[i];
		while(p>=0 && arr[p]>tmp)
		{
			arr[p+1] = arr[p];
			p--;
		}
		arr[p+1] = tmp;
	}
}

void qSort(int arr[NUM],int start,int end)
{
	if(start >= end)
	{
		return;
	}
	int i = 0, j = 0;
	int fdata = 0;
	i = start;
	fdata = i;
	j = end;
	while(i<j)
	{
		while(i<j && arr[fdata]<=arr[j])
		{
			j--;
		}
		if(i<j && arr[fdata]>arr[j])
		{
			myswap(arr+fdata,arr+j);
			fdata = j;
		}
		
		while(i<j && arr[fdata]>=arr[i])
		{
			i++;
		}
		if(i < j && arr[fdata]<arr[i])
		{
			myswap(arr+fdata,arr+i);
			fdata = i;
		}
	}
	qSort(arr,start,fdata-1);
	qSort(arr,fdata+1,end);
}

void initArray(int arr[NUM])
{
	srand((unsigned int)time(NULL));
	int i = 0;
	for(i=0;i<NUM;i++)
	{
		arr[i] = rand()%1000;
	}
}

void displayArray(int arr[NUM])
{
	int i = 0;
	for(i=0;i<NUM;i++)
	{
		printf("%d ",arr[i]);
	}
	putchar('\n');
}

int main(void)
{
	int arr[NUM] = {0};
	initArray(arr);
	struct timeval tv;
	gettimeofday(&tv,NULL);

	int64_t start = (int64_t)tv.tv_sec*1000+tv.tv_usec/1000;
//	dubbleSort(arr); 
//	selectSort(arr);
//	insertSort(arr);
	qSort(arr,0,NUM-1);

	gettimeofday(&tv,NULL);

	int64_t end = (int64_t )tv.tv_sec*1000+tv.tv_usec/1000;
	printf("the time is %lu ms\n",end-start);
}

