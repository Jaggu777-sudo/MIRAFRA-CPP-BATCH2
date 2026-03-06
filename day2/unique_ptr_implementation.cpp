#include<iostream>
#include<memory>
using namespace std;
template<typename T>
class uniqueptr{
	private:
		T* res;
	public:
		uniqueptr():res(nullptr){}
		uniqueptr(T *a):res(a){}
		~uniqueptr(){
			delete res;
		}
		uniqueptr(const uniqueptr& other)=delete;
		uniqueptr& operator=(const uniqueptr&other)=delete;
		uniqueptr(uniqueptr&&other)
		{
			res=other.res;
			other.res=nullptr;
		}
		uniqueptr& operator =(uniqueptr&& other)
		{
			if(this!=&other){
			res=other.res;
			other.res=nullptr;
			}
			return *this;
		}
		T& operator *(){
			return *res;
		}
		T* operator->(){
			return res;
		}
		bool operator !(){
			return res==nullptr;
		}
		void reset(T *ptr=nullptr){
		delete res;
		res=ptr;
		}
		T* get()const{
		return res;
		}
		T* release(){
		T* temp=res;
		 res=nullptr;
		return temp;
		}
};
class Test{
	public:
	int data;
		Test(int val):data(val){}
		void hello()
		{
			cout<<"Data:"<<data<<endl;
		}
};
void alter(Test *ptr){

ptr->data=100;
}
int main()
{
	uniqueptr<Test>ptr1(new Test(10));
	ptr1->hello();
	uniqueptr<Test>ptr2=move(ptr1);
	if(!ptr1){
		cout<<"ptr1 is nullptr after move"<<endl;
	}
	//ptr1->hello();
	ptr2->hello();
	alter(ptr2.get());
	ptr2->hello();
}
