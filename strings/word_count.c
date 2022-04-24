#include<stdio.h>

int main()
{
	char A[] = "A quick brown fox jumped over a lazy dog.";
	int i,wcount = 1;
	for(i=0;i<40;i++)
		if(A[i] == ' ' && A[i-1] != ' ')//extra condition to check for consecutive white space
			wcount++;
	printf("%d\n",wcount);
	return 0;
}
