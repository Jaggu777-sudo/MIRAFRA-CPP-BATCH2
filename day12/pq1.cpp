#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Task{
	public:
		int id;
		string name;
		int burst_time;
		Task(int i,string s,int bs):id(i),name(s),burst_time(bs){}

		friend ostream& operator<<(ostream& os,const Task& other){
			os<<other.id<<" "<<other.name<<" "<<other.burst_time<<endl;
			return os;
		}
};
struct compare{

	bool operator()(const Task&t1,const Task& t2)const{
		cout<<"comparater exected"<<endl;
		if(t1.id==t2.id)
			return t1.burst_time<t2.burst_time;
		return t1.id<t2.id;
	}
};

int main(){
	priority_queue<Task,vector<Task>,compare> pq;

	pq.push(Task(1,"Task1",5));
	pq.push(Task(1,"Task2",3));
	pq.push(Task(3,"Task3",8));
	pq.push(Task(4,"Task4",1));

	while(!pq.empty()){
		cout<<pq.top();
		pq.pop();
	}

	return 0;
}

