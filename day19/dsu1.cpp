#include <iostream>
#include <vector>
using namespace std;
void printDSU(const vector<int>& parent, const vector<int>& rank)
{
    cout << "Parent: ";
    for(int p : parent)
        cout << p << " ";
    cout << endl;
    cout << "Rank  : ";
    for(int r : rank)
        cout << r << " ";
    cout << endl;
    cout << "------------------------\n";
}
void makeSet(vector<int>& parent, vector<int>& rank, int n)
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node) // parent
        return node;

    return parent[node] = findParent(parent, parent[node]); //path Compression 
    // parent[node]
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u); //u=2 parent(2)->0
    v = findParent(parent, v); //v=6 parent(6)->5

    if(u == v)
    {
        cout << "Nodes " << u << " and " << v 
             << " are already in same set\n";
        return;
    }

    if(rank[u] < rank[v]) // 1-2
    {
        parent[u] = v;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else //ranks are equal 
    {
        parent[v] = u;
        rank[u]++; // 0->1
    }
    cout << "Union done between " << u << " and " << v << endl;
    printDSU(parent, rank);
}

int main()
{
    int n = 7;
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(parent, rank, n);

    cout << "Initial State:\n";
    printDSU(parent, rank);

    unionSet(0, 1, parent, rank); 
    unionSet(1, 2, parent, rank); 
    unionSet(3, 4, parent, rank);
    unionSet(5, 6, parent, rank); 
    unionSet(2, 6, parent, rank);

    cout << "\nChecking connectivity:\n";

    if(findParent(parent, 0) == findParent(parent, 6)) // path compression
        cout << "0 and 6 are connected\n";
    else
        cout << "0 and 6 are NOT connected\n";

    if(findParent(parent, 3) == findParent(parent, 0))
        cout << "3 and 0 are connected\n";
    else
        cout << "3 and 0 are NOT connected\n";

    return 0;
}
