#include<iostream>
using namespace std;
void (*fp)(int );
void led_on(int pin){

	cout<<"led is connected with "<<pin<<endl;

}
void motor_on(int pin){
	cout<<"motor is connected to "<<pin<<endl;

}
int main()
{
	int t;
	cout<<"enter temparature value"<<endl;
	cin>>t;
	if(t>25)
	{
		fp=motor_on;
		fp(17);
	}
	else{
		fp=led_on;
		fp(13);

	}
}
