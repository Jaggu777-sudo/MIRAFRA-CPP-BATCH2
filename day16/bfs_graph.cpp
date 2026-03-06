#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& adj)
{ // start =0
    int V = adj.size();

    vector<bool> visited(V, false);

    queue<int> q; // FIFO

    // Start node
    visited[start] = true; // visited[0] = true; 
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " "; // removing 0 , add neighbors to Q

        // Visit neighbors
        for (int neighbor : adj[node]) //adj[0]= {1, 2};  ...neighbor =2
        {
            if (!visited[neighbor]) // !visited[1] =!F
            {
                visited[neighbor] = true; //visited[1] =T
                q.push(neighbor); //1 ,2
            }
        }
    }
    cout<<endl;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    cout << "BFS Traversal: ";
    bfs(0, adj);

    return 0;
}
