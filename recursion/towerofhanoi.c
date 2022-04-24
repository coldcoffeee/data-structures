#include<stdio.h>

void TOH(int n, int A, int B, int C)
{
	if(n>0)
	{
		TOH(n-1,A,C,B);
		printf("%d to %d\n",A,C);
		TOH(n-1,B,A,C);
	}
}

/*wrong approach
 * void TOH(int n, int A, int B, int C)
{
	if(n>1)
	{
		TOH(n-1,A,C,B);
		TOH(n-1,A,B,C);
		TOH(n-1,B,A,C);
	}
	if(n==1)
	{
		printf("%d to %d\n",A,C);
	}
}*/

int main()
{
	TOH(3,1,2,3);
	return 0;
}
