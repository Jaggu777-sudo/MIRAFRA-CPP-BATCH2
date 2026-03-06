#include<iostream>
//#include<functional>
//#include<vector>
using namespace std;
void func(auto value)
{

cout<<"inside function"<<value<<endl;

}
int main()
{

int a=10;
auto generic_lamda=[&](auto x,auto y){
return a+x+y;
//vector<int>v1={1,2,3,4,5};


};
func(generic_lamda(10.3,20));


}
