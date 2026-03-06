
//custom deletor for files

#include<iostream>
#include<memory>
#include<cstdlib>
#include<cstdio>

using namespace std;
class custom_del
{
	public:
		template<typename T>
			void operator() (T*p)const
			{
				cout<<"array gets cleaned\n";
				delete []p;
			}

};



int main()
{

	unique_ptr<int [],custom_del>p(new int [10],custom_del());


}
