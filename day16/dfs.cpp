#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS function
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    //visited[node] = true;        // Mark current node as visited
    cout << node << " ";         // Print the node

    // Visit all neighbors
    for(int neighbor : adj[node])
    {
        if(!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

int main()
{
    int V = 5;   // Number of vertices
    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);
   // dfs(0, adj, visited);
    // Adding edges (Undirected graph)
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(0);
    adj[0].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    

    cout << "DFS Traversal: ";
    dfs(4, adj, visited);

    return 0;
}
