#include<stdio.h>

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void perm(char S[],int l,int h)
{
	int i;
	if(l==h)
	{
		printf("%s\n",S);
	}
	else
	{
		for(i=l;i<=h;i++)
		{
			swap(S+i,S+l);
			perm(S,l+1,h);
			swap(S+i,S+l);
		}
	}
}

int main()
{
	char string[20];
	printf("Enter a string: "),scanf("%[^\n]s",string);
	
	printf("String is: ");

	int len = printf("%s",string);
	printf("\n");
	
	printf("Permutations are:\n");

	perm(string,0,len-1);


	return 0;
}
