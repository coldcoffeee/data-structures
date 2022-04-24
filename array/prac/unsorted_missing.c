#include<stdio.h>

int main()
{
	int A[] = {6,1,4,3,5,9,8,10};
	int n = 8;
	int l=A[0],h=0;
	int i;
	for(i=0;i<n;i++)
	{
		l = l>A[i]?A[i]:l;
		h = h<A[i]?A[i]:h;
	}

	int B[10] = {0};
	
	for(i=0;i<=h;i++)
		B[A[i]]++; //hashing demo

	i=l;
	while(1)
	{
		if(!B[i])
			printf("%d ",i);
		if(i==h)
			break;
		i++;
	}
	B[11] = 99;
	return 0;
}
