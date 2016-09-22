//TSP
#include<stdio.h>
#include<stdlib.h>

int g(int i,int s,int cost[10][10],int set[10],int n)
{
	int min,j,k,selected[10],newset[10];
	for(j=1;j<=n;j++)
	{
		newset[j]=set[j];
	}
	newset[i]=0;
	if(s==0)
	{
		return cost[i][1];
	}
	for(k=0,j=2;k<s;j++)
	{
		if(newset[j])
		{
			selected[k]=cost[i][j]+g(j,s-1,cost,newset,n);
			k++;
		}
	}
	min=999;
	for(j=0;j<s;j++)
	{
		if(selected[j]<min)
		{
			min=selected[j];
		}
	}
	return min;
}
int approx(int cost[10][10],int n)
{
	int i,j,next,visited[10],dist,min;
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	visited[1]=1;
	dist=0;
	for(i=1;i<n;i++)
	{
		min=999;
		for(j=1;j<=n;j++)
		{
			if((cost[i][j]!=0)&&(cost[i][j]<min)&&(!visited[j]))
			{
				next=j;
				min=cost[i][j];
			}
		}

		dist=dist+min;
		visited[next]=1;
	}
	dist=dist+cost[next][1];
	printf("minimum cost using approximation algorithm is %d\n",dist);
	return dist;
}
void main()
{
	int i,j,s[10],cost[10][10],n,a,b;
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			s[i]=1;
		}
	}
	printf("the cost adjacency matrix is\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
	printf("the minimum cost of optimal tour is %d\n",a=g(1,n-1,cost,s,n));
	b=approx(cost,n);
	printf("the approximation tour is %d percent longer than optimal tour\n",((b*100)/a)-100);
}


