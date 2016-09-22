/*Obtain the Topological ordering of vertices in a given digraph.*/
#include <iostream>
using namespace std;

class topological_sorting
{
	int n;				//Number of nodes in the graph
	int a[10][10];			//Cost adjacency matrix
	int indegree[10];		//Indegree of all nodes
public:
	void read_data();
	void find_indegree();
	void topological_sort();
};

void topological_sorting::read_data()
{
	cout<<"Enter the number of jobs"<<endl;
	cin>>n;

	cout<<"Enter the adjacency matrix"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
}

void topological_sorting::find_indegree()
{
	for(int j=0;j<n;j++)
	{
		int sum=0;
		for(int i=0;i<n;i++) 
			sum+=a[i][j];
		indegree[j]=sum;
	}
	cout<<"Indegrees are"<<endl;
	for(int i=0;i<n;i++)
		cout<<indegree[i]<<" ";
}

void topological_sorting::topological_sort()
{
	int u,v,t[10],s[10];

	find_indegree();

	int top=-1;			// Set top to -1 for the stack 
	int k=0;
	for(int i=0;i<n;i++)		//Placing jobs on stack
		if(indegree[i]==0) 
			s[++top]=i;
	while(top!=-1)
	{						//Finding the topological sequence 
		u=s[top--];				//Delete the job from stack
		t[k++]=u;

		for(v=0;v<n;v++)
		{
			if(a[u][v]==1)
			{
				indegree[v]--;
				if(indegree[v]==0) 
					s[++top]=v;
			}
		}
	}
	cout<<"The Topological Sequence is"<<endl;
	for(int i=0;i<n;i++)
		cout<<t[i]<<" ";
}

int main()
{
	topological_sorting t;
	t.read_data();
	t.topological_sort();
}
