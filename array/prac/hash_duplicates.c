#include<stdio.h>
int main()
{
	int A[] = {2,1,2,6,4,5,9,7,1,7,8,6,9};
	int l = 1, h = 9;
	int B[10]={0};
	int n = 13;

	int i;
	for(i=0;i<n;i++)
	{
		B[A[i]]=B[A[i]]+1;
	}
	for(i=l;i<=h;i++)
	{
		if(B[i]>1)
			printf("%d repeats for %d times\n",i,B[i]);
	}
	return 0;
}
