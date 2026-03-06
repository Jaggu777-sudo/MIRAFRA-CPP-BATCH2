#include<iostream>
#include<memory>
using namespace std;
class Car;
class Person{
	public:
		shared_ptr<Car>c;
		static int count;
		Person(){
			count++;
			cout<<"Person Object Created"<<endl;
		}
		~Person(){
			count--;
			cout<<"Person Object Destroyed"<<endl;
		}

};
class Car{
	public:
		static int count;
		weak_ptr<Person>p;
		Car(){
			count++;
			cout<<"Car Object is Created"<<endl;

		}
		~Car(){
			count--;
			cout<<"Car Object Is Destroyed"<<endl;
		}
};
int Person::count=0;
int Car::count=0;
int main()
{
	{
	cout<<"Inside Block"<<endl;
	auto sp1=make_shared<Person>();
	auto sp2=make_shared<Car>();
	sp1->c=sp2;
	sp2->p=sp1;
	cout<<"Person::count "<<Person::count<<endl;
	cout<<"Car::count "<<Car::count<<endl;
	cout<<"reference Count "<<sp2.use_count()<<endl;
	}
	cout<<"After Block"<<endl;
	cout<<"Person::count "<<Person::count<<endl;
	cout<<"Car::count "<<Car::count<<endl;
}
