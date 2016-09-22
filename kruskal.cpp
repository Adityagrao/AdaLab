  /*Find Minimum Cost Spanning Tree of a given undirected graph
using Kruskal's algorithm.*/

#include <iostream>
using namespace std;

int find(int x,int parent[])
{
	while (parent[x]!=x) x=parent[x];
	return x;
}

void union_ij(int i,int j,int parent[])
{
	if(i<j) parent[j]=i;
	else	parent[i]=j;
}


class KRUSKAL
{
	int cost_adjacency_matrix[10][10];
public:
	int number_of_nodes;
	int number_of_edges;
	void obtain_cost_adjacency_matrix();
	void minimum_spanning_tree();
};

void KRUSKAL::obtain_cost_adjacency_matrix()
{
	int i,j,u,v;

	//Initialize cost matrix
	for(i=0;i<number_of_nodes;i++)
		for(j=0;j<number_of_nodes;j++)
			cost_adjacency_matrix[i][j]=999;	//Setting all nodes as not reachable

	//Setting the nodes with their edge value

	for(i=0;i<number_of_edges;i++)
	{
		cout<<"Enter the node number of U and V\n";
		cin>>u>>v;
		cout<<"Enter the edge value between "<<u<<" and "<<v<<endl;
		cin>>cost_adjacency_matrix[u][v];
		// Because Undirected Weighted graph
		cost_adjacency_matrix[u][v]==cost_adjacency_matrix[v][u]; 
	}

}

void KRUSKAL::minimum_spanning_tree()
{
	int i,parent[10],min,j,u,v,k,t[10][2],sum,count;
	count=0;	//Initilize number of edges selected as none
	k=0;		//Points to the first selected edge of minimum spanning tree
	sum=0;		//Initial cost of minimum spanning tree 

	for(i=0;i<number_of_nodes;i++) parent[i]=i;	//Create a forest with the number of nodes

	while(count<number_of_nodes)
	{
		min=999;
		// Finding the edge with minimum weight 
		for(i=0;i<number_of_nodes;i++)
			for(j=0;j<number_of_nodes;j++)
				if(cost_adjacency_matrix[i][j]<min)
				{
					min=cost_adjacency_matrix[i][j];
					u=i;
					v=j;
				}
		if(min==999) break; 						//No more edges to select

		i=find(u,parent);							//Finding the root of the vertex u
 		j=find(v,parent);							//Finding the root of the vertex v

 		if(i!=j)					// If the roots of the vertex u and v are different 
 		{
 			//Select the edge (u,v) as the edge on the minimum spanning tree
 			t[k][0]=u , t[k][1]=v;
 			k++;
 			count++;
 			sum+=min;
 			union_ij(i,j,parent); // merge the two trees with the root i and j
 		}
 		//Deleting the edge (u,v) by setting to high value
 		cost_adjacency_matrix[u][v]=cost_adjacency_matrix[v][u]=999;		
 	}
 	if(count == number_of_nodes-1)
 	{
 		cout<<"Cost of the spanning tree = "<<sum<<endl;
 		cout<<"Spanning tree is shown below"<<endl;
 		for(k=0;k<number_of_nodes-1;k++) cout<<t[k][0]<<","<<t[k][1]<<endl;
 		return;
 	}
 	cout<<"Spanning tree does not exist"<<endl;
}



int main()
{
	KRUSKAL k;
	cout<<"Enter the number of nodes"<<endl;
	cin>>k.number_of_nodes;

	cout<<"Enter the number of edges"<<endl;
	cin>>k.number_of_edges;

	cout<<"Enter the edge list"<<endl;
	k.obtain_cost_adjacency_matrix();

	k.minimum_spanning_tree();
	return 0;

}