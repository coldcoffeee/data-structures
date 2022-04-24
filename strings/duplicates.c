//smol 97 to 122 capital 65 to 90
#include<stdio.h>

int main()
{
	char str[100];
	printf("Enter a sentence: "),scanf("%[^\n]s",str);

	int H[26]={0};

	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>=65 && str[i]<=90)
			H[str[i]-65]++;
		else if(str[i]>=97 && str[i]<=122)
			H[str[i]-97]++;
		else continue;
	}

	for(i=0;i<26;i++)
	{
		if(H[i])
		{
			printf("%c -> %d\n",i+65,H[i]);
		}
	}
	return 0;
}
