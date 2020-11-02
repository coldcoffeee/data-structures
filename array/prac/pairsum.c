#include<stdio.h>

int main()
{
	int A[] = {4,5,3,7,6,5,9,1};
	int k = 10;
	int B[10] = {0};
	int i;
	for(i=0;i<8;i++)
		B[A[i]]++;
	for(i = 1;i<=9;i++)
	{
		if(B[i]>0)
		{
			if(B[k-i]>0)
			{
				printf("%d + %d = %d\n",i,k-i,k);
				B[k-i] = 0;
			}
		}
	}
	return 0;
}
