#include<iostream>
#include<memory>
using namespace std;
//template<typename T>
class sharedptr{
	private:
		int *res;
		int* count;
		void increment(){
			(*count)++;
		}
		void decrement(){
			if(count){
				(*count)--;
				if((*count)==0){
						delete res;
						delete count;
				}
			}
		}
	public:
		sharedptr():res(nullptr),count(nullptr){}
		sharedptr(int* ptr):res(ptr),count(new int(1)){}
		sharedptr(const sharedptr&other)
		{
			cout<<"copy constructor called"<<endl;
			res=other.res;
			count=other.count;
			increment();

		}
		sharedptr(sharedptr&&other)noexcept
		{
			cout<<"Move Constructor called"<<endl;
			res=other.res;
			count=other.count;
			other.res=nullptr;
			other.count=nullptr;
		}
		sharedptr& operator =(const sharedptr&other)
		{
			cout<<"Copy Assigment called"<<endl;
			if(this!=&other){
				decrement();
				res=other.res;
				count=other.count;
				increment();
			}
			return *this;
		}
		sharedptr& operator =(sharedptr&&other)noexcept{
		cout<<"Move assigment is called"<<endl;
		if(this!=&other)
		return *this;
		decrement();
		res=other.res;
		count=other.count;
		other.res=nullptr;
		other.count=nullptr;
		}
		~sharedptr(){
			decrement();
		}
	int get_reference_count(){
		return *count;
		}
		void reset(int *ptr){
		decrement();
		res=ptr;
		count=new int(1);
		}
		int* operator ->(){
			return res;
		}
		int& operator *(){
		return *res;
		}
};
int main()
{
	sharedptr p(new int(10));
	{
	sharedptr p1=p;
	}
	sharedptr p2(p);
	sharedptr p3=move(p);
	p3=p2;
	
	cout<<"count reference "<<p3.get_reference_count()<<endl;
}
