#include<stdio.h>

int main()
{
	int A[] = {1,3,4,5,7,8,9};
	int  k = 10;
	int i = 0, j = 6;
	while(i<j)//can't use i<=j because (5,5) isn't a pair because bofa same numbers
	{
		if(A[i]+A[j] == k)
		{
			printf("%d + %d = %d\n",A[i],A[j],k);
			i++;j--;
		}
		else if(A[i]+A[j] > k)
			j--;
		else if(A[i]+A[j] < k)
			i++;
	}
	return 0;
}
