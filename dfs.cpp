#include<iostream>
using namespace std;
class GRAPH
{
	int n;				//Number of vertices in the graph
	int cost[10][10];		//Adjacency matrix
public:
	void read_matrix();			//Reads the adjacency matrix
	void dfs(int u,int s[]);		//Traverse the graph in DFS
	int connectivity();			//Check for the connectivity of the graph
};

void GRAPH::read_matrix()
{
	int i,j;


	cout<<"Enter the number of nodes"<<endl;
	cin>>n;

	cout<<"Enter the cost adjacency matrix"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>cost[i][j];
}

void GRAPH::dfs(int u,int s[])
{
	int v;
	s[u]=1;
	for(v=0;v<n;v++)
		if(cost[u][v]==1 && s[v]==0)
			dfs(v,s);
}

int GRAPH::connectivity()
{
	int i,j,flag,s[10];
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++) s[i]=0;

		dfs(j,s);
		flag=0;
		for(i=0;i<n;i++)
			if(s[i]==0)  flag=1;
		if(flag==0) return 1;
	}
	return 0;
}

int main()
{
	GRAPH g;
	g.read_matrix();
	int flag=g.connectivity();
	if(flag==1)
		cout<<"The Graph is Connected"<<endl;
	else
		cout<<"The Graph is not Connected"<<endl;
	return 0;
}
