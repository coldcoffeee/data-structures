#include<stdio.h>

int main()
{
	char name[] = "mOHIT gUPTA";
	int i;
	for(i=0;i<11;i++)
	{
		if(name[i] >= 'a' && name[i] <= 'z')
			name[i]-=32;
		else if(name[i] >= 'A' && name[i] <= 'Z')
			name[i]+=32;
	}
	printf("%s\n",name);
	return 0;
}
