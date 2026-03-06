#include<iostream>
#include<vector>
#include<unordered_map>
#include<utility>
#include<climits>
#include<queue>
using namespace std;
class ECU{
	unordered_map<string,vector<pair<string,int>>>adj;
	public:
	void add_edge(string u,string v,int routing_cost){
		adj[u].push_back({v,routing_cost});
		adj[v].push_back({u,routing_cost});
	}
	vector<pair<string,pair<string,int>>> CalculatePrismMST(string source_ecu){
		auto f=adj.find(source_ecu);
		if(f==adj.end()){
			return {};
		}
		unordered_map<string,int>key;
		unordered_map<string,string>parent;
		unordered_map<string,bool>vis;
		for(auto& node:adj){
			key[node.first]=INT_MAX;
			vis[node.first]=false;
		}
		priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
		key[source_ecu]=0;
		pq.push({0,source_ecu});
		while(!pq.empty()){
			auto[cost,u]=pq.top();
			pq.pop();
			if(vis[u])
				continue;
			vis[u]=true;
			for(auto &[v,c]:adj[u]){
				if(!vis[v] && c<key[v]){
					key[v]=c;
					parent[v]=u;
					pq.push({key[v],v});
				}
			}
		}
	vector<pair<string,pair<string,int>>>result;
	for(auto &p:parent){
		result.push_back({p.first,{p.second,key[p.first]}});
	}
	return result;
	}
};
int main(){
	ECU e;
	e.add_edge("Engine Control","Battery Management",3);
	e.add_edge("Engine Control","Dashboard",4);
	e.add_edge("Battery Management","Dashboard",2);
	e.add_edge("Battery Management","ADAS Camera",6);
	e.add_edge("Dashboard","ADAS Camera",5);
	e.add_edge("Dashboard","Rear Parking Sensor",7);
	e.add_edge("ADAS Camera","Infotainment",4);
	e.add_edge("Rear Parking Sensor","Infotainment",3);
	auto mst=e.CalculatePrismMST("Engine Control");
	for(auto &edge : mst) {
	  cout << edge.second.first  << " -> "   << edge.first << "  Cost: " << edge.second.second << endl;
    }
	return 0;
}

