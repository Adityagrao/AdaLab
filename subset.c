/*Find a subset of a given set S = {s l , s 2 ,.....,s n } of n positive integers
whose sum is equal to a given positive integer d. For example, if S=
{1, 2, 5, 6, 8} and d = 9 there are two solutions{1,2,6}and{1,8}.A
suitable message is to be displayed if the given problem instance
doesn't have a solution.*/

#include<stdio.h>

int count;
int w[10];
int d;
int x[10];

void subset(int cs,int k,int r)
{
	int i;
	x[k]=1;

	if(cs+w[k]==d)
	{
		printf("\nThe Sub Set Solution is %d\n",++count);
		for(i=0;i<=k;i++)
			if(x[i]==1) printf(" %d ",w[i]);
	}
	else if(cs+w[k]+w[k+1]<=d)
		subset(cs+w[k],k+1,r-w[k]);
	if(cs+r-w[k]>=d && cs+w[k+1]<=d)
	{
		x[k]=0;
		subset(cs,k+1,r-w[k]);
	}
}

int main()
{
	int sum=0,i,n;
	printf("Enter the number of elements\n");
	scanf("%d",&n);

	printf("Enter the elements in ascending order\n");
	for(i=0;i<n;i++) scanf("%d",&w[i]);

	printf("Enter the required sum\n");
	scanf("%d",&d);

	for(i=0;i<n;i++) sum+=w[i];

	if(sum<d)
	{	
		printf("No Solution\n");
		return 0;
	}
	
	count=0;
	subset(0,0,sum);
	printf("\n");
	return 0;
}