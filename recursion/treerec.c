#include<stdio.h>

void tree(int n)
{
	if(n>0)
	{
		tree(n-1);
		tree(n-1);
		printf("%d",n);
	}
}
int main()
{
	tree(3);
	return 0;
}
