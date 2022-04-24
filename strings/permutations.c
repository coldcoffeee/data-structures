#include<stdio.h>

void perm(char S[], int k)
{
	static int A[15] = {0};
	static char Res[15];
	int i;

	if(S[k] == '\0')
	{
		Res[k] = '\0';
		printf("%s\n",Res);
		return;
	}

	else
	{
		for(i=0;S[i]!='\0';i++)
		{
			if(A[i] == 0)
			{
				A[i] = 1;
				Res[k] = S[i];
				
				perm(S,k+1);

				A[i] = 0;
			}
		}
	}
}

int main()
{
	char S[30];
	
	printf("Enter a word: "),scanf("%[^\n]s",S);

	printf("Possible permutations are:\n");
	
	perm(S,0);

	return 0;
}
