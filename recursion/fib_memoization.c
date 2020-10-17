#include<stdio.h>

//int arr[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

static int arr[30];
int fib(int n)
{
	
	if(n<=1)
	{
		arr[n] = n;
		return n;
	}

	else
	{
		if(arr[n-2] == -1)
			arr[n-2] = fib(n-2);
		if(arr[n-1] == -1)
			arr[n-1] = fib(n-1);
		arr[n] = arr[n-2] + arr[n-1]; //isse hum values ko store kar rahe hain, bina store kare bhi direct return kar sakte hain par store karna better lagta hai
		return arr[n-2] + arr[n-1];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	/*Below line sets each index value of global variable arr to -1*/
	for(i=0;i<30;i++)
		arr[i] = -1;
	
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",fib(i));
	}
	return 0;
}
