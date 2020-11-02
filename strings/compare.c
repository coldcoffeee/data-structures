#include<stdio.h>
int main()
{
	char A[30],B[30];
	int i,j;
	printf("Enter two words: ");
	scanf("%s",A);
	scanf(" ");
	scanf("%s",B);
	for(i=0,j=0;A[i]!='\0' || B[j]!='\0';i++,j++)
	{
		if(A[i]!=B[j])
			break;
		else
			continue;
	}
	if(A[i] == B[j])
		printf("Bofa equal.\n");
	else if(A[i] > B[j])
		printf("%s appears before %s in a dictionary.",B,A);
	else
		printf("%s appears before %s in a dictionary.",A,B);
	return 0;
}
