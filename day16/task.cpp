#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define MAX 5

struct Module
{
    string module_name;
    bool status;
};

int graph[MAX][MAX] = {0};
bool visited[MAX] = {false};

void dfs_iterative(int start, Module module[])
{
    stack<int> st;
    st.push(start);

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!visited[node])
        {
            visited[node] = true;

            if(!module[node].status)
            {
                module[node].status = true;
             
              cout << "Activating: "<< module[node].module_name<<"->"<<(module[node].status ? "ON" : "OFF")<< endl;
	
            for(int i = MAX - 1; i >= 0; i--)
            {
                if(graph[node][i] == 1 && !visited[i])
                {
                    st.push(i);
                }
            }
        }
    }
}
}
int main()
{
    Module module[MAX] ={{"Engine Control", false},{"Fuel System", false},{"Ignition", false}, {"Sensor Module", false}, {"Logging System", false}};

    graph[0][1] = 1; // Engine → Fuel
    graph[0][2] = 1; // Engine → Ignition
    graph[1][3] = 1; // Fuel → Sensor
    graph[2][3] = 1; // Ignition → Sensor
    graph[3][4] = 1; // Sensor → Logging

    cout << "Starting ECU Feature Activation\n\n";

    dfs_iterative(0, module);

    return 0;
}
