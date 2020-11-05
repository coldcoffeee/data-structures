//program fails if length of the string is same and letters are repeating
#include<stdio.h>

// two words are anagram if they have same letters e.g. medical & decimal

int main()
{
	char A[15];
	char B[15];

	printf("Enter 2 lowercase words: "),scanf("%s %s",A,B);

	printf("\nWords are: %s %s",A,B);

	int HA=0,HB=0,x,y;

	int i;

	for(i=0;A[i]!='\0';i++)
	{
		x = 1,y=1;
		x = x << A[i]-97;
		y = y<<  B[i]-97;

		HA |= x;
		HB |= y;

	}
	if(A[i]!=B[i])
	{
		printf("\nStrings are unequal in length.");
		return 0;
	}
	
	if(HA == HB)
		printf("\nThey're Anagram.\n");
	else
		printf("\nThey're not Anagram.\n");
	return 0;
}
