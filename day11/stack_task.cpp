#include<iostream>
#include<stack>
using namespace std;
struct S{

	int pid;
	string process_name;
	bool running_status;

	S(int id,string s,bool rs=false):pid(id),process_name(s),running_status(rs){}
	friend ostream& operator<< (ostream &os,S& obj){
		os<<obj.pid<<" "<<obj.process_name<<" "<<boolalpha<<obj.running_status<<" "<<endl;
		return os;
	}

};

int main(){

	stack<S>s1;
	cout<<"Adding Struct objetcs"<<endl;
	s1.push({10,"A",true});
	s1.push({20,"B",false});
	s1.push({30,"C",true});
	cout<<"Total "<<s1.size()<<" ele are added"<<endl;
	while(!s1.empty()){
		cout<<s1.top();	
		s1.pop();
	}
	return 0;
}

