#include<iostream>
#include<array>
using namespace std;
void func(array<int,5>&a1){
	int *p=a1.data();
	for(int i=0;i<5;i++){
	p[i]=i*100;
	}
	for(auto i:a1){
		if(i%3==0){
			cout<<i<<" ";
		}
	}
	cout<<endl;
}
int main(){
	array<int,5>a1={10,20,30,40,50};
	func(a1);
//	fill(a1.begin(),a1.end(),100);
	cout<<"After Filling"<<endl;
	for(auto i:a1){
	cout<<i<<" ";
	}
	cout<<endl;
}
