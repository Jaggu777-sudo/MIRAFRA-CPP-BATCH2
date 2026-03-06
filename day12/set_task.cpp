#include<iostream>
#include<set>
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
		if(t1.id==t2.id)
			return t1.burst_time<t2.burst_time;
		return t1.id<t2.id;
	}
};

int main(){
	set<Task,compare>s1;
	s1.insert(Task(1,"Task1",5));
	s1.insert(Task(1,"Task2",3));
	s1.insert(Task(3,"Task3",8));
	s1.insert(Task(4,"Task4",1));
	auto it=s1.find(Task(3,"",0));
	if(it!=s1.end()){
	cout<<"Found"<<endl;
	}
	
	for(const auto& x:s1){
		cout<<x<<" ";
	}		
	cout<<endl;	

	return 0;
}

