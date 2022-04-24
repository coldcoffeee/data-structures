#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A[5] = {0};
	printf("%d\n",3[A]);//A[3]===3[A]
	
	int *p = (int *) malloc(5 * sizeof(int));

	int i,j;
	for(i=0;i<5;i++)
		p[i] = i;
	int *q =(int *) malloc(10 * sizeof(int));
	for(i=0;i<5;i++)
		q[i] = p[i];
	free(p);
	p=q;
	q=NULL;

	for(i=0;i<5;i++)
		printf("%d\n",*(p+i));
	int *D[3];//pointer of arrays
	
	for(i=0;i<3;i++)
		D[i] = (int *) malloc(4 * sizeof(int));
	int **E;
	E = (int **) malloc(3*sizeof(int *));//mallocate the array of pointers
	E[0] = (int *)malloc(4*sizeof(int));//mallocate each row of the array
	E[1] = (int *)malloc(4*sizeof(int));//```````````````````````````````
	E[2] = (int *)malloc(4*sizeof(int));//```````````````````````````````
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			E[i][j] = i*j;
			printf("%d\t",E[i][j]);
		}
		printf("\n");
	}
	free(E);
	free(*D);//free(D) won't work because D is in Stack meanwhile the pointers at *D can be freed
	return 0;
}
