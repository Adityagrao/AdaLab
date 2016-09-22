/*Using OpenMP, implement a parallelized Merge Sort algorithm to
sort a given set of elements and determine the time required to sort
the elements. Repeat the experiment for different values of n, the
number of elements in the list to be sorted and plot a graph of the
time taken versus n. The elements can be read from a file or can be
generated using the random number generator.*/
//gcc mergesort.c -lgomp -o test

#include <omp.h>
#include <stdio.h>
void merge(int a[],int first,int mid,int last)
{
	int i,j,k=0,b[30000];
	i=first;
	j=mid+1;
	while(i<=mid && j<=last)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=last)
		b[k++]=a[j++];
	for(i=first;i<=k;i++)
		a[i]=b[i];
}

void mergesort(int a[],int first,int last)
{
	int mid,i;
	if(first<last)
	{
		mid=(first+last)/2;
		#pragma omp paralle
		{
			mergesort(a,first,mid);
			mergesort(a,mid+1,last);
		}
		merge(a,first,mid,last);
	}
}

void main()
{
	int i,n,a[30000];
	double start,end;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		a[i]=rand()%20;
	printf("The array before sorting\n");
	for(i=0;i<n;i++) printf(" %d ",a[i]);
	start=omp_get_wtime( );
	mergesort(a,0,n-1);
	end=omp_get_wtime( );
	printf("The sorted array is\n");
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	printf("The time taken is %f\n",(end-start));

}