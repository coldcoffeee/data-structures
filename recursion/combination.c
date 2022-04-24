#include<stdio.h>

int c(int n, int r) //recursive 
{
	if(r == 0 || r == n) 
		return 1;

	else 
		return c(n-1,r-1) + c(n-1,r); //from pascal's triangle
}

int fact(int n)
{
	if(n<=1) 
		return 1;
	else 
		return n * fact(n-1);
}

int iC(int n, int r)//iterative  //O(n)
{
	int N = fact(n);//O(n)
	int R = fact(r);//O(n)
	int NminusR = fact(n-r);//O(n)
	
	return N/(R * NminusR);
}

int main()
{
	printf("%d",c(5,3));
	return 0;
}
/* this code has O(r):
 *int nCr (int n, int r)

{

    if (r == 0)

         return 1;

   else

        return(((n-r+1) * nCr(n, r-1))/r);

}
This has order of complexity: O(r)
*/
