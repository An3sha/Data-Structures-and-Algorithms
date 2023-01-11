// Adjacent Matrix


/* Pros: Representation is easier to implement and follow. Removing an edge takes O(1) time. Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done O(1).
Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space. Adding a vertex is O(V^2) time.  Computing all neighbors of a vertex takes O(V) time (Not efficient). */


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
  // n is the number of vertices
  // m is the number of edges
  int n, m;
  cin >> n >> m;
  int a[n+1][n+1];
  
  for(int i=0; i<m; i++)
  {
    int u, v;
    cin >> u >> v;
    a[u][v]=1;
    a[v][u]=1;
  }
  return 0;
}



// Adjacent List

// The size of the array is equal to the number of vertices.
//Space required for directed graph: Θ(V + E)
//Space required for undirected graph: Θ(V + 2*E)

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}
 
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
    return 0;
}
