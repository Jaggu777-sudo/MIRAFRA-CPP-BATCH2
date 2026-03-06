#include <iostream>
#include <vector>

using namespace std;

// DFS function to detect cycle in directed graph
bool dfs(int node,
         vector<vector<int>> &adj,
         vector<bool> &visited,
         vector<bool> &recStack)
{
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node])
    {
        // If not visited, recurse
        if (!visited[neighbor])
        {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        // If neighbor is in recursion stack → cycle
        else if (recStack[neighbor])
        {
            return true;
        }
    }

    // Remove node from recursion stack before returning
    recStack[node] = false;
    return false;
}

int main()
{
    int V = 4;  // Number of vertices

    vector<vector<int>> adj(V);

    // Add directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);  // Creates a cycle

    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    bool cycleExists = false;

    // Handle disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, recStack))
            {
                cycleExists = true;
                break;
            }
        }
    }

    if (cycleExists)
        cout << "Cycle detected in directed graph\n";
    else
        cout << "No cycle found\n";

    return 0;
}
