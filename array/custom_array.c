#include<stdio.h>
#include<stdlib.h>
typedef struct Ar{
	int *A;
	int size;
	int length;
}Array;

void print(Array *arr)
{
	int i;
	for(i=0;i<arr->length;i++)
		printf("%d ",arr->A[i]);
	printf("\n");
}

void display(Array *arr, int index)
{
	(index<arr->length && index>=0)?printf("%d\n",arr->A[index]):printf("Index out of bounds.\n");
}

void insertAt(Array *arr,int index,int n)
{
	if(index == 0 && arr->length == 0)
		arr->A[arr->length++] = n;
	if(index>=0 && index < arr->length)
	{		int i;
		for(i=arr->length;i>index;i--)
			arr->A[i] = arr->A[i-1];
		arr->A[index] = n;
		arr->length++;
	}
}

void insertX(Array *arr, int n)
{
	if(arr->length == arr->size)
		return;
	int i = arr->length-1;
	while(arr->A[i] > n && i>=0)
	{
		arr->A[i+1] = arr->A[i];
		i--;
	}
	arr->A[i+1] = n;
	arr->length++;
}

void append(Array *arr, int n)
{
	arr->A[arr->length++] = n;
}

void delete(Array *arr,int index)
{
	if(index>=0 && index < arr->length)
	{
		int i;
		for(i=index;i<arr->length-1;i++)
			arr->A[i] = arr->A[i+1];
		arr->length--;

	}
}

void max(Array *arr)
{
	int i=0,max=-1;
	for(i=0;i<arr->length;i++)
	{
		max = max>arr->A[i]?max:arr->A[i];
	}
	printf("Max value: %d\n",max);
}

void search(Array *arr, int num)
{
	int i;
	for(i=0;i<arr->length;i++)
	{
		if(arr->A[i] == num)
		{
			printf("%d found at index no. %d\n",num,i);
		}
		if(i == arr->length)
			printf("%d not found int the array!\n");
	}
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(Array *arr)
{
	int mid = (arr->length)/2;
	int i;
	for(i=0;i<mid;i++)
	{
		swap(&(arr->A[i]),&(arr->A[arr->length-i-1]));
	}
}

void trim(Array *arr,int n)
{
	int i,j;
	if(n>=0)
	{
		arr->length-=n;
	}

	else
	{
		n=-n;
		while(n--)
		{
			for(i=0;i<arr->length-1;i++)
				arr->A[i] = arr->A[i+1];
			arr->length--;
		}
	}
}

void rotate(Array *arr,int n)
{
	int temp;
	int i;
	if(n==0)
		return;
	else if(n<0)
	{
		n*=-1;
		while(n--)
		{
			temp  = arr->A[0];
			for(i=0;i<arr->length-1;i++)
			{
				arr->A[i] = arr->A[i+1];
			}
			arr->A[arr->length-1] = temp;
		}
	}
	else if(n>0)
	{
		while(n--)
		{
			temp  = arr->A[arr->length-1];
			for(i=arr->length-1;i>0;i--)
			{
				arr->A[i] = arr->A[i-1];
			}
			arr->A[0] = temp;
		}
	}
}

Array *init(Array *arr)
{
	arr = (Array *) malloc(sizeof(Array));	
	arr->size = 20;
	arr->A = (int *) malloc(arr->size * sizeof(int));
	return arr;
}

int isSorted(Array *arr)
{
	int i;
	for(i=0;i<arr->length-1;i++)
	{	
		if(arr->A[i]>arr->A[i+1])
		{
			return 0;
		}
	}
	return 1;
}

void rearrange(Array *arr)//negative elements to left and positive elements to the right
{
	int i,j;
	i = 0;
	j = arr->length-1;
	while(i<j)
	{
		while(arr->A[i]<0)i++;
		while(arr->A[j]>0)j--;
		if(i<j) swap(&arr->A[i],&arr->A[j]);
	}
}

void  merge(Array *a, Array *b, Array *c)
{
	c->length = a->length + b->length;
	c->size = a->size + b->size;

	int i=0,j=0,k=0;
	while(i<a->length && j<b->length)
	{
		if(a->A[i] < b->A[j])
			c->A[k++] = a->A[i++];
		else
			c->A[k++] = b->A[j++];
	}
	for(;i<a->length;i++)
		c->A[k++] = a->A[i];
	for(;j<b->length;j++)
		c->A[k++] = b->A[j];
}

int main()
{
	Array *arr1,*arr2,*arr3;
	int i;

	arr1 = (Array *) malloc(sizeof(Array));
	arr2 = (Array *) malloc(sizeof(Array));
	arr3 = (Array *) malloc(sizeof(Array));
	
	arr1->length = 4;
	arr1->size = 10;
	arr1->A = (int *) malloc(arr1->size * sizeof(int));
	arr2->length = 5;
	arr2->size = 10;
	arr2->A = (int *) malloc(arr2->size * sizeof(int));
	
	for(i=0;i<arr1->length;i++)
		arr1->A[i] = i+1;
	for(i=0;i<arr2->length;i++)
		arr2->A[i] = i+5;

	merge(arr1,arr2,arr3);

	print(arr1);
	print(arr2);
	print(arr3);
	return 0;
}
