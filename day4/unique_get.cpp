#include<iostream>
#include<memory>
using namespace std;

void change(int *p)
{
*p=20;
cout<<endl;
cout<<"addrss :"<<p<<"value :"<<*p<<endl;
//delete p;
}


int main()
{
unique_ptr<int>uniqueptr=make_unique<int>(10);
cout<<"before passing\n";
cout<<"unique ptr value :"<<*uniqueptr<<"address of uniqueptr :"<<&uniqueptr<<"adress of ptr inside uniqueptr :"<<uniqueptr.get()<<"value of ptr inside uniqueptr :"<<*uniqueptr.get()<<endl;
change(uniqueptr.get());
cout<<"after passig\n";
cout<<"value :"<<*uniqueptr.get()<<endl;
if(uniqueptr)
{
cout<<"ownershp not transfered\n";
}
else
{
cout<<"ownership get transferd\n";
}
}
