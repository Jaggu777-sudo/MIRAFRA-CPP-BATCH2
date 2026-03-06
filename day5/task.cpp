#include<iostream>
#include<memory>
using namespace std;
class Temp{
	public:
		int size;
		float *data;
		Temp(int s):size(s){
			data=new float[size];
		}
		void set_temp_value(){

			cout<<"enter temp values"<<endl;
			for(int i=0;i<size;i++){
				cin>>data[i];
			}

		}
		void get_temp_values(){
			for(int i=0;i<size;i++){
				cout<<data[i]<<" ";
			}
		}
		~Temp(){

			delete []data;

		}

};
class custom_deleter{

	public:
		void operator ()(Temp *T){
			if(T){
				delete T;
			}
		}


};
void change(shared_ptr<Temp>p){
	float avg=0;
	for(int i=0;i<p->size;i++){
		avg=avg+p->data[i];

	}
	avg/=p->size;
	cout<<"Avg Temparature "<<avg<<endl;
}
int main(){

	shared_ptr<Temp>s1(new Temp(5),custom_deleter{});
	s1->set_temp_value();
	s1->get_temp_values();
	change(s1);

}
