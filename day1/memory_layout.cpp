#include<iostream>
using namespace std; 
static int x;//unintialized data segment(BSS)
int main() 
{ 
	int y; //stack segment
	int *p=new int[1]; //Heap segment
	static int z=10; //Intialiazed data Segment
	cout<<"Uninitialized Data Segment "<<&x<<endl; 
	cout<<"stack section: "<<&y<<endl; 
	cout<<"Heap Section: "<<p<<endl; 
	cout<<"Intializaed Data Segment "<<&z<<endl;
	delete p;
}
