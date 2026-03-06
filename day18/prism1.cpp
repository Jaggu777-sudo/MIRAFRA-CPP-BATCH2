#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<utility>
using namespace std;
class graph{
unordered<char,vector<pair<char,int>>>adj;
public:
void add_edge(char u,char v,int weight){
adj[u].push_back({v,weight});
adj[v].push_back({u,weight});
}
unordered_map<char,pair<char,int>>CalculateMST(int n,char source){
vector<char,bool>vis;
unordered_map<char,int>key;
unorderd_map<char,char>parent;
priority_queue<pair<char,int>,vector<char,int>,greater<int,int>>pq;
key[source]=0;
pq.push({0,source});
while(!pq.empty()){
auto[k,u]=pq.top();
pq.pop();
if(vis[k-97])
continue;
vis[k-97]=true;
for(auto[v,weight]:adj[u]){
if(!vis[v-97]&&weight<key[v]){
key[v]=weight;
parent[v]=u;
pq.push({key[v],v});
}
}
}
}

};
int main(){
graph g;
a.add_edge('S','A',12);
a.add_edge('S','B',8);
a.add_edge('A','B',9);
a.add_edge('A','C',22);
a.add_edge('A','E',11);
a.add_edge('B','C',16);
a.add_edge('B','E',14);
a.add_edge('C','D',15);
a.add_edge('C','E',18);
a.add_edge('D','E',3);
auto mst=CalculateMST(6,'S');

	return 0;
}

