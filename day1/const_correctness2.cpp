#include<iostream>
using namespace std;
int & func(int &a)
{

return a;

}

int main()
{
int a=10;
int &b=a;
const int &m=func(a);
cout<<func(a)<<endl;

cout<<&a<<" "<<&b<<endl;

int p=10;
const int &q=a;
p=100;
//q=200;//b is const reference

}
