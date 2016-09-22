/*Implement All-Pairs Shortest Paths Problem using Floyd's
algorithm. Parallelize this algorithm, implement it using OpenMP
and determine the speed-up achieved.*/

#include <iostream>
using namespace std;

int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

class floyd
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

void floyd::write_data()
{
	cout<<"The Path matrix is shown below"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}
}

void floyd::read_data()
{
	cout<<"Enter the number of nodes\n"<<endl;
	cin>>n;

	cout<<"Enter the adjecency matrix"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
}

void floyd::path_matrix()
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) 
			p[i][j]=a[i][j];  //Making a copy of the adjacency matrix

	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				p[i][j]=min(p[i][j],p[i][k]+p[k][j]);		// I think, I already know this 
}

int main()
{
	floyd w;
	w.read_data();
	w.path_matrix();
	w.write_data();
}
