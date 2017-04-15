#include <iostream>
using namespace std;

class prims
{
	int n;			//Number of nodes in the graph
	int a[10][10];		//Cost adjacency matrix

public:
	void read_data();
	void minimum_spanning_tree();
};

void prims::minimum_spanning_tree()
{
	int i,j,u,v,min;
	int sum;		//Holds the cost of the MST
	int k;			//Index
	int t[10][2];		//Holds MST
	int p[10];		//Holds vertices visited
	int d[10];		//Holds weights 
	int s[10];		//Info in if vertix is visited or not

	int source;		//Starting vertx

	//Finding the source with min edge
	min=999;
	source=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=0 && a[i][j]<=min)
			{
				min=a[i][j];
				source=i;
			}

	//Inserting the first min node into the MST
	for(i=0;i<n;i++)
	{
		d[i]=a[source][i];
		s[i]=0;
		p[i]=source;
	}

	s[source]=1;		//Select source as 1 
	sum=0;
	k=0;
	
	for(i=1;i<n;i++)	//Finiding u and D[u] such that it is min
	{
		min=999;
		u=-1;
		for(j=0;j<n;j++)
			if(s[j]==0 && d[j]<min)
			{
				min=d[j];		//Edge with least cost
				u=j;	
			}
		t[k][0]=u;				//Insert into the MST
		t[k][1]=p[u];
		k++;

		sum+=a[u][p[u]];			//Update sum
		s[u]=1;
		for(v=0;v<n;v++)
			if(s[v]==0 && a[u][v]<d[v])	//Find d[v] and p[v] for V 
			{
				d[v]=a[u][v];
				p[v]=u;
			}
	}

	if(sum>999)
		cout<<"Spanning Tree does not exist"<<endl;
	else
	{
		cout<<"Spanning Tree Exist and Minmum Spanning Tree is"<<endl;
		for(i=0;i<n-1;i++)
			cout<<t[i][0]<<" "<<t[i][1]<<endl;
		cout<<"The cost of the spanning tree is="<<sum<<endl;
	}
}

void prims::read_data()
{
	int i,j;
	cout<<"Enter the number of nodes"<<endl;
	cin>>n;

	cout<<"Enter the cost adjacency matrix"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
}

int main()
{
	prims a;
	a.read_data();
	a.minimum_spanning_tree();
	return 0;
}
