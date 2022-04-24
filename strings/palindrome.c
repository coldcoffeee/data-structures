#include<stdio.h>

int areEqual(char A[],char B[])
{
	int i,j;
	for(i=0,j=0;A[i]!='\0' || B[j]!='\0';i++,j++)
	{
		if(A[i]!=B[j])
			return 0;
	}	

	if(A[i]!=B[j])
		return 0;
	return 1;
}

int isPalindrome(char A[])
{
	char B[20];
	int i,j;
	for(i=0;A[i]!='\0';i++);
	i--;
	for(j=0;i>=0;i--,j++)
	{
		B[j] = A[i];
	}
	B[j] = '\0';
	
	if(areEqual(A,B))
		return 1;
	return 0;
}
int main()
{
	printf("Enter a word: ");
	char A[30];
	scanf("%s",A);
	int i=0;
	while(A[i]!='\0')
	{
		if(A[i]>=65 && A[i]<=90)
			A[i]+=32;
		i++;
	}
	isPalindrome(A)?printf("%s is a palindrome.\n",A):printf("%s is not a palindrome.\n",A);
	return 0;
}
