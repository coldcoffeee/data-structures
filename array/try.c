
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Ar{
	int A[10];
	int size;
	int length;
}Array;

void print(Array *arr)
{
	int i;
	for(i=0;i<arr->length;i++)
		printf("%d ",arr->A[i]);
	printf("\n");
}

int main()
{
	Array arr = {{1,2,3,4,5,6,7,8},10,8};
	print(&arr);
	return 0;
}
