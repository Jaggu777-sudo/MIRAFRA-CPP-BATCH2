#include<iostream>
using namespace std;
constexpr int sum(int a,int b){
	return a+b;
}
int main()
{
	constexpr int a=sum(10,20);
	cout<<a<<endl;

	int b=sum(20,30);
	cout<<b<<endl;

}
