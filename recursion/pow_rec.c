#include<stdio.h>

int pow(int m, int n)
{
	printf("called\n");
	if(n == 0)
		return 1;
	if(n%2 == 0)
		return pow(m*m,n/2);
	else
		return m*pow(m*m,(n-1)/2);
}

int main()
{
	printf("%d ",pow(2,9));
	return 0;
}
