#include<iostream>
#include<vector>
using namespace std;
template<class T>
class DGraph{
int V;
vector<vector<T>>adjMatrix;
public:
DGraph(int vertices):V(vertices),adjMatrix(V,vector<T>(V,T{}){}
void add_edge(int src,int des,T weight){
if(src>=0 && src<V && des>=0 && des<V){
adjMatrix[src][des]=weight;
}
}
void print()const{
for(int i=0;i<V;i++){
for(int j=0;j<V;j++){
cout<<adjMatrix[i][j]<<" ";
}
cout<<endl;
}
}
};
int main(){
DGraph<int> g(5);
g.add_edge(0,1,3);
g.add_edge(0,2,1);
g.add_edge(0,3,3);
g.add_edge(1,3,1);
g.add_edge(4,3,2);
g.print();
	return 0;
}

