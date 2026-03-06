#include<iostream>
#include<memory>
using namespace std;
class Gpio
{
	int pin;
	public:
	Gpio(int p=0){
		pin=p;
		cout<<"Gpio pin: "<<pin<<" is Intialized"<<endl;

	}

	int getpin()
	{
		return pin;

	}


};
class custom_deleter{

	public:
		void operator ()(Gpio *ptr)
		{
			if(ptr){

				delete ptr;
			}
		}

};
void moduleA(shared_ptr<Gpio>g){
	cout<<"Module A is using Gpio"<<g->getpin()<<endl;
	cout<<"module A use_count"<<g.use_count()<<endl;
}
void moduleB(shared_ptr<Gpio>*g){
	*g=shared_ptr<Gpio>(new Gpio(13),custom_deleter{});
	cout<<"Module B is using Gpio"<<(*g)->getpin()<<endl;
	cout<<"module B use_count"<<(*g).use_count()<<endl;
}
int main()
{
	shared_ptr<Gpio>sp1(new Gpio(17),custom_deleter{});
	moduleA(sp1);
	moduleB(&sp1);
	cout<<"sp1 use_count"<<sp1.use_count()<<endl;

}
