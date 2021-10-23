/*.   										IMPLEMENTING GRAPH
									       ____________________
									       
									       1. EDGE LIST
									       2. ADJACENCY MATRIX
									       3. ADJACENT LIST
									       
									       
									       ADJACENT LIST
									      _________________
									      
									   - Most widely used and useful
									   - easily find neighbours of node stored in a array linked list (or hashmaps)
									   - memory efficient
									   
									   
									   0 ----------- 1
									   |           / | \
									   |	     /	 |  \
									   |	   /	 |   \2
									   |	 /  	 |.  /
									   |.  /	 |  /
									   | /		 | /
									   4 ----------- 3
									   
									   0 --> 1, 4
									   1 --> 0, 2, 3, 4
									   2 --> 1, 3
									   3 --> 1, 2, 4
									   4 --> 0, 1, 3
*/
									      


#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int> *l;					//pointer


public:

	Graph(int v)					//constructor
	{
		V = v;					// V is vertices
		l = new list<int>[V];
	}
	
	void addEdge(int u, int v, bool bidir=true)	//u and v are edges, bidir is bidirectional
	{
		l[u].push_back(v);
		if(bidir)
		{
			l[v].push_back(u);
		}
	}

	void printAdjList()
	{
		for(int i=0; i<V; i++)
		{
			cout<<i<<"-->";
			//l[i] is a linked list
			for(int vertex: l[i])
			{
				cout<<vertex<<",";
			}
			cout<<endl;
		}
	}

};

int main()
{
	Graph g(5);				  //graph has 5 vertices numbered from 0 to 4
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);

	g.printAdjList();

	return 0;

}
