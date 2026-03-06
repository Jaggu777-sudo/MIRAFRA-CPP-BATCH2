#include <iostream>
#include <vector>

using namespace std;
/*
0 — 1
|   |
3 — 2
*/
// DFS function to detect cycle
bool dfs(int node, int parent,vector<vector<int>>& adj,vector<bool>& visited) 
{
    visited[node] = true;//v[0]=T T F F

    for (int neighbor : adj[node]) //nei=1
    {
        // If neighbor not visited → continue DFS
        if (!visited[neighbor]) // if(!v[1])
        {
            if (dfs(neighbor, node, adj, visited)) 
                return true;
        }
        // If visited and not parent → cycle detected
        else if (neighbor != parent) // node =3, parent=2
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int V = 6;  // number of vertices

    // Create adjacency list
    vector<vector<int>> adj(V);

    // Add edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[4].push_back(5);
    adj[5].push_back(4);

    vector<bool> visited(V, false); 

    bool cycleExists = false;

    // Handle disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited)) 
            {
                cycleExists = true;
                break;
            }
        }
    }

    if (cycleExists)
        cout << "Cycle detected in graph\n";
    else
        cout << "No cycle found\n";

    return 0;
}
