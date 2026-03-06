#include<iostream>
#include<queue>
using namespace std;
int main(){
priority_queue<int>q;
priority_queue<int,vector<int>,greater<int>>pq;
q.push(10);
q.push(20);
q.push(30);
pq.push(100);
pq.push(200);
pq.push(300);
while(!q.empty()){
cout<<q.top()<<" ";
q.pop();
}
cout<<endl;
cout<<pq[2]<<endl;
while(!pq.empty()){
cout<<pq.top()<<" ";
pq.pop();
}
cout<<endl;
	return 0;
}

