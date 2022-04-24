#include<stdio.h>

int main()
{
	int A[] = {6,7,9,10,11,12,14,15,17};
	int i;
	int n = sizeof(A)/sizeof(int);
	int l = A[0],h = A[n-1];
	int diff = A[0] - 0;
	printf("Missing numbers: ");
	for(i=1;i<n;i++)
	{
		if((A[i]-i) != diff)
		{
			printf("%d ",i+diff);
			diff = A[i]-i;
		}
	}

	return 0;
}
