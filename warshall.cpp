/*Compute the transitive closure of a given directed graph using
Warshall's algorithm.*/

#include <iostream>
using namespace std;

class warshall
{
private:
	int n;		//Number of nodes in the graph
	int a[10][10];	//Cost adjecency matrix 
	int p[10][10];	//Path matrix
public:
	void path_matrix();
	void read_data();
	void write_data();
};

void warshall::write_data()
{
	cout<<"The Path matrix is shown below"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}
}

void warshall::read_data()
{
	cout<<"Enter the number of nodes\n"<<endl;
	cin>>n;

	cout<<"Enter the adjecency matrix"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
}

void warshall::path_matrix()
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) 
			p[i][j]=a[i][j];  //Making a copy of the adjacency matrix

	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(p[i][k]==1 && p[k][j]==1)
					p[i][j]=1;		// I think, I already know this 
}

int main()
{
	warshall w;
	w.read_data();
	w.path_matrix();
	w.write_data();
}
