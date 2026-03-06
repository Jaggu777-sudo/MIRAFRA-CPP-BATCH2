#include<iostream>
#include<memory>
using namespace std;
int main(){
	auto sp1=make_shared<int>(25);
	weak_ptr w1=sp1;
	cout<<sp1.use_count()<<endl;
	//cout<<"*w1= "<<*w1<<endl;we cannot dereference weak_ptr directly
	if(auto sp2=w1.lock()){
		cout<<*sp2<<endl;
	cout<<sp1.use_count()<<endl;
	}
	else{
		cout<<"Object Is Destroyed"<<endl;
	}
}

