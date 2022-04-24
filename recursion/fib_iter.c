#include<stdio.h>

void fib(int n)
{
	int i=0;
	long long int t0 = 0;
	long long int t1 = 1;
	long long int t2;
	
	if(n==t0)
		return;	
	else if(n==t1)
		printf("%lld",t0);
	else
		printf("%lld %lld ",t0,t1);
	for(i=2;i<n;i++)
	{
		t2 = t0 + t1;
		t0 = t1;
		t1 = t2;
		printf("%lld ",t2);
	}

	printf("\n");
}

int main()
{
	int n;

	printf("Enter the number of terms you want to print: ");
	scanf("%d",&n);

	fib(n);

	return 0;
}
