#include<iostream>
#include<utility>
#include<list>
#include<unordered_map>
#include<limits>
#include<optional>
using namespace std;
template<typename N,typename T>
class Graph{
	unordered_map<N,list<pair<N,T>>>adjList;
	public:
	void add_edge(N u,N v,T weight,bool directed=false){
		adjList[u].push_back({v,weight});
		if(!directed){
			adjList[v].push_back({u,weight});
		}
	}
	void print(){
		cout << "City Graph:\n";
		for(const auto& [key, neighbour] : adjList){
			cout << key << " -> ";
			for(const auto& [nei, weight] : neighbour){
				cout << "(" << nei << "," << weight << ") ";
			}
			cout << endl;
		}
	}

	optional<pair<N,T>> shortest_distance(N node){
		if(adjList.empty()) return nullopt;

		auto it = adjList.find(node);
		if(it == adjList.end())  // node not found
			return nullopt;

		const auto& l = it->second;   // reference, not copy
		if(l.empty())                  //no neighbours
			return nullopt;

		T minWeight = std::numeric_limits<int>::max();
		N minNeighbour = " ";

		for(const auto& [neighbour, weight] : l){
			if(weight < minWeight){
				minWeight = weight;
				minNeighbour = neighbour;
			}
		}

		return make_pair(minNeighbour, minWeight);
	}



};
int main(){
	Graph<string,double> g;

	g.add_edge("Hitech City","Madhapur",3.2);
	g.add_edge("Hitech City","KPHB",1.8);
	g.add_edge("Madhapur","Durgam Cheruvu",4.1);
	g.add_edge("Madhapur","Kokapet",2.5);
	g.add_edge("KPHB","Kokapet",2.0);
	g.add_edge("Kokapet","Durgam Cheruvu",5.9);
	g.print();
	auto s1 = g.shortest_distance("Madhapur");
	if(s1){
		cout << "Shortest neighbour of Madhapur':\n";
		cout << "Node: " << s1->first
			<< " Distance: " << s1->second << " km\n";
		cout << "___________________\n";
	}

	auto s2 = g.shortest_distance("Hitech City");
	if(s2){
		cout << "Shortest neighbour of 'Hitech city':\n";
		cout << "Node: " << s2->first
			<< " Distance: " << s2->second << " km\n";
	}
}

