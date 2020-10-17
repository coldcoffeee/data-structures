#include<stdio.h>
int sum(int n)
{
	if(n)
		return n+sum(n-1);
	else
		return 0;
}
int main()
{
	printf("%d",sum(5));
}
