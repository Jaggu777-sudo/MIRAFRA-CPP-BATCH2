#include<iostream>
#include<unordered_map>
int main(){

std::unordered_map<int,int>um;
um.insert({1,10});
um.insert({2,20});
std::cout<<um[2]<<std::endl;
std::cout<<um.at(1)<<std::endl;
std::cout<<um[3]<<std::endl;
}
