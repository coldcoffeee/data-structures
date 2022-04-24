#include<stdio.h>

int main()
{
    char name[] = "Enola Holmes";
    int i = -1, c = 0;
    while(name[++i]!='\0')
	    c++;
    printf("%d\n",c);
    return 0;
}
