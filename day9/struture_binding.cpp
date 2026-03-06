#include<iostream>
using namespace std;
struct S
{
mutable int x;
volatile double y;

};
S f(){
return S{1,2.3};
}
int main(){

const auto [x,y]=f();
cout<<x<<" "<<y<<endl;
x=-2;//allowed because x is mutable
//y=-2;//y is const
S s_var={10,23.5};
const auto[x1,y1]=s_var;
cout<<x1<<" "<<y1<<endl;


}
