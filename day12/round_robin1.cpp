#include<iostream>
#include<queue>
using namespace std;
struct Process{
	int id;
	int burst_time;
	int remaining_time;


};
int main(){

	queue<Process>q;
	q.push({1,5,5});
	q.push({2,3,3});
	q.push({3,1,1});
	int timeslice=4;
	int current_time=0;
	while(!q.empty()){

		auto&[id,bt,rt]=q.front();
		q.pop();
		std::cout << "Executing P" << id<< " at time " << current_time;
		if(rt>timeslice){

			current_time+=timeslice;
			rt=rt-timeslice;
			std::cout << " for " << timeslice << " units\n";

			q.push({id,bt,rt});
		}
		else{

			current_time += rt;

			std::cout << " for " << rt << " units (Finished)\n";

			rt = 0;
		}
	}


}


