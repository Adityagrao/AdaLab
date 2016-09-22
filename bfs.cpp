#include<iostream>
using namespace std;

class BFS
{
	public:
		void bfs_traversal();
		void read_data();
		void print_data();
	private:
		int n;			//Number of vertices in the graph
		int s[20];		//Holds the info on the nodes that are reachable
		int a[20][20];		//Adjacency matrix of the garph
		int source;		//From where BFS has to take place
};

void BFS::read_data()
{
	cout<<"Enter the number of nodes"<<endl;
	cin>>n;

	cout<<"Enter the Adjacency matrix"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	cout<<"Enter the source"<<endl;
	cin>>source;
}

void BFS::print_data()
{
	//Display the nodes that are reachable and not reachable
	for(int i=0;i<n;i++)
	{
		if(s[i]==0)
			cout<<"Vertex "<<i<<" is not reachable"<<endl;
		else
			cout<<"Vertex "<<i<<" is reachable"<<endl;
	}
}

void BFS::bfs_traversal()
{
	int f,r,q[20];	//queue
	int u,v;	//represent the vertex
	int i;		//index

	for(i=0;i<=n;i++) s[i]=0;	//No nodes are visited in the beginning 
	f=r=0;
	q[r]=source;			//Insert the source vertex in the queue
	s[source]=1;			//Indicate that the soruce is visited

	while(f<=r)				//As long as the queue is not empty
	{
		u=q[f++];			//Delete the vertex to be visited from the queue

		for(v=1;v<=n;v++)
		{
			// To find the nodes V which are adjacent to u
			if(a[u][v]==1 && s[v]==0)
			{
				s[v]=1;		//add v to s to indicated it is visited 
				q[++r]=v;	// insert new vertex into Q for exploration
			}
		}

	}

}

int main()
{
	BFS a;
	a.read_data();
	a.bfs_traversal();
	a.print_data();
	return 0;
}
