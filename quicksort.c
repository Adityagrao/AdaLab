/*Sort a given set of elements using the Quicksort method and
determine the time required to sort the elements. Repeat the
experiment for different values of n, the number of elements in the
list to be sorted and plot a graph of the time taken versus n.
The elements can be read from a file or can be generated using the
random number generator.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

void generate_random(int a[],int n);
void quicksort(int a[],int p,int q);
int partation(int a[],int low,int high);
void swap(int a[],int left,int right);

int main()
{
	int array[10000],i,n;
	struct timeval t;
	double start,end;
	printf("Array Lenght\t\tTime Taken\n");
	for(i=1000;i<10000;i+=500)
	{
		generate_random(array,i);
		gettimeofday(&t,NULL);
		start=t.tv_sec+(t.tv_usec/1000000.0);
		quicksort(array,0,i-1);
		gettimeofday(&t,NULL);
		end=t.tv_sec+(t.tv_usec/1000000.0);
		printf("%d\t\t\t%f\n",i,end-start);
	}

	return 0;
}

void generate_random(int a[],int n)
{
	int i;
	srand(time(0));
	for(i=0;i<n;i++)
		a[i]=rand()%10000;
}

void quicksort(int a[],int p,int q)
{
	int j;
	if(p<q)
	{
		j=partation(a,p,q);
		quicksort(a,p,j-1);
		quicksort(a,j+1,q);
	}
}

int partation(int a[],int low,int high)
{
	int temp;
	int pivot=a[low];
	int i=low;
	int j=high;
	while(1)
	{
		while(a[i]<pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j && a[i]!=a[j])
			swap(a,i,j);
		else
			return j;
	}
}

void swap(int a[],int left,int right)
{
	int temp;
	temp=a[left];
	a[left]=a[right];
	a[right]=temp;

}
