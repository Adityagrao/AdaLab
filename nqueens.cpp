#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;

void print_solution(int n,int x[])
{
	char c[10][10];
	int i,j;

	//No queens has been placed
	for( i=1;i<=n;i++)
		for( j=0;j<=n;j++)
			c[i][j]='X';

	//Place the queens on the chess board
	for(i=1;i<=n;i++)
		c[i][x[i]]='Q';

	//Print the queens
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<c[i][j];
		cout<<endl;
	}
}

int place(int x[],int k)
{
	for(int i=1;i<k;i++)
		if(x[i]==x[k] || i-x[i]==k-x[k] || i+x[i]==k+x[k]) return FALSE;
	return TRUE;
}

void nqueens(int n)
{
	int x[10];
	int count=0;

	int k=1;
	x[k]=0;

	while(k!=0)
	{
		x[k]+=1;
		while(x[k]<=n && (!place(x,k)))
			x[k]+=1;
		if(x[k]<=n)
		{
			if(k==n)
			{
				count++;
				cout<<"Solution "<<count<<" is"<<endl;
				print_solution(n,x);
			}
			else
				x[++k]=0;
		}
		else
			k--;
	}
}

int main()
{
	int n;
	cout<<"Enter the number of queens"<<endl;
	cin>>n;
	nqueens(n);
	return 0;
}
