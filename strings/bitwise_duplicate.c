#include<stdio.h>//one bit for each letter of the alphabet

int main()
{
	char A[100];
	printf("Enter a sentence: "),scanf("%[^\n]s",A);

	long int H = 0, x = 0;//H for a 26-bit hash since C has no variable of 26 bits so we take long int of size 32bits>26bits || x for masking merging

	int i;
	for(i=0;A[i]!='\0';i++)
	{
		x = 1;//so that we mat do Lshift for masking or merging
		
		if(A[i]>=65 && A[i] <=90)
			x = x << A[i]-65;
		else if(A[i]>=97 && A[i] <=122)
			x = x << A[i]-97;		//enabling A[i]'s bit in x
		else
			continue;

		if(x&H)//i.e. if A[i]'s bit already enabled in H
			printf("%c repeated\n",A[i]);
		else
			H = H | x; //i.e. enable A[i]'s bit in H to make it detectable for repetition
	}

	return 0;
}
