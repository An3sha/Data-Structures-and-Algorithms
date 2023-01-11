/* 
Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public: 
        // Function to return Breadth First Traversal of given graph.
        vector<int> bfsofgraph(int V, vector<int> adj[]) {
          
          int visited[V] = {0};
          visited[0] = 1;
          queue<int> q;
          // push the initial starting node 
          q.push(0);
          vector<int> bfs;
          // iterate till the queue is empty 
          while(!q.empty()) {
            // get the topmost element in the queue 
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            // traverse for all its neighbours 
            for(auto it : adj[node]) {
               // if the neighbour has previously not been visited, 
                // store in q and mark as visited 
              if(!visited[it]) {
                visited[it] = 1;
                q.push(it);
              }
            }
          }
          
          return bfs;
        }
};

void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printAns(vector<int> &ans) {
  for(int i=0; i< ans.size(); i++){
    cout<<ans[i]<<" ";
  }
}

int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);
  
    Solution obj;
    vector<int> ans = obj.bfsofgraph(5, adj);
    printAns(ans);
    return 0;
}

          
