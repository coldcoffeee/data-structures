#include<stdio.h>

int main()
{
	char A[20],B[20];

	printf("Enter two lowercase words: "),scanf("%s %s",A,B);

	int H[26]={0};

	int i;

	for(i=0;A[i]!='\0';i++)
	{
		H[A[i]-97]++;
	}

	for(i=0;B[i]!='\0';i++)
	{
		H[B[i]-97]--;
		if(H[B[i] - 97] < 0)
		{
			printf("\nNot Anagram.");
			return 0;
		}
	}

	printf("\nAnagram.");
	return 0;
}
