#include<iostream>
#include<memory>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
using namespace std;
class A
{

int data;
public:
A(int value=0):data(value){}
~A(){

cout<<"destructor"<<endl;
}

};
int main()
{

shared_ptr<A>sp1=make_shared<A>(10);
cout<<sp1.use_count()<<endl;
{
auto sp2=sp1;
shared_ptr<A>sp3;
sp3=sp2;
cout<<sp3.use_count()<<endl;
}
}


