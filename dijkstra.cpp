/*From a given vertex in a weighted connected graph, find shortest
paths to other vertices using Dijkstra's algorithm.*/

#include <iostream>
using namespace std;

class dijkstra
{
	int n;				//Number of nodes in the graph
	int a[10][10];			//Cost Adjacency matrix
	int d[10];			//Holds the shortest distance
	int p[10];			//Holds the shortest path from a source to distination
public:
	void read_data();
	void print_path();
	void optimal_solution(int source,int dest);
};

void dijkstra::optimal_solution(int source,int dest)
{
	int i,j,u,v,min;
	int visited[10];			//Holds the information of reachablity

	for(i=0;i<n;i++)
	{
		d[i]=a[source][i];
		visited[i]=0;
		p[i]=source;
	}
	visited[source]=1; //Add source as S

	for(i=1;i<n;i++)
	{
		min=999;
	 	u=-1;
	 	for(j=0;j<n;j++)
	 		if(visited[j]==0 && d[j]<min)
	 		{
	 			min=d[j];
	 			u=j;
	 		}
	 	if (u==-1) return;

	 	visited[u]=1;
	 	if(u==dest) return;

	 	for(v=0;v<n;v++)
	 		if(visited[v]==0 && d[u]+a[u][v]<d[v])
	 		{
	 			d[v]=d[u]+a[u][v];
	 			p[v]=u;
	 		}
	}
}

void dijkstra::read_data()
{
	int i,j;
	cout<<"Enter the number of nodes"<<endl;
	cin>>n;

	cout<<"Enter the cost Adjacency matrix"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
}

void dijkstra::print_path()
{
	int source,dest;
	cout<<"Enter the source"<<endl;
	cin>>source;
	
	for(dest=0;dest<n;dest++)
	{
		optimal_solution(source,dest);

		if(d[dest]==999)
			cout<<dest<<" is not reachable from "<<source<<endl;
		else
		{
			cout<<"The shortest path is shown below"<<endl;
			int i=dest;
			while(i!=source)
			{
				cout<<i<<"<--";
				i=p[i];
			}
			cout<<i<<" = "<<d[dest]<<endl;
		}
	}
}

int main()
{
	dijkstra a;
	a.read_data();
	a.print_path();
}
