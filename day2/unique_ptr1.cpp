#include<iostream>
#include<memory>
using namespace std;

class dis
{
int c;

public:
dis(int a=0):c(a)
{
cout<<"constructor"<<endl;

}
~dis()
{
cout<<"destructor"<<endl;

}

void print(dis *obj)
{

cout<<"previous "<<obj->c<<endl;
obj->c=obj->c+10;
cout<<"after "<<c<<endl;
}

};

int main()
{
unique_ptr<dis>p1=make_unique<dis>(10);
p1->print(p1.get());
p1->print(p1.get());
}
