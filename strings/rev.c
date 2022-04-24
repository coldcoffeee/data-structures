#include<stdio.h>
int main()
{
	char S[30],t;
	printf("Enter a sentence: ");
	scanf("%[^\n]s",S);
	int i,j;
	for(i=0;S[i]!='\0';i++);
	i--;
	for(j=0;j<i;j++,i--)
	{
		t = S[j];
		S[j] = S[i];
		S[i] = t;
	}
	printf("%s\n",S);
	return 0;
}
