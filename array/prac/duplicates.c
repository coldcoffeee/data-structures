#include<stdio.h>

int main()
{
	int A[] = {2,3,3,4,5,6,7,7,7,8,9};
	int i,dup=0,cdup=1;
	int n = 11;
	for(i=0;i<n-1;i++)
	{
		if(A[i]==A[i+1])
		{
			cdup++;
			dup = A[i];
		}
		
		else if(dup)
		{
			printf("%d occurs for %d times\n",dup,cdup);
			cdup = 1;
			dup = 0;
		}
	}

	return 0;
}
