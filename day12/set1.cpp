#include <iostream>
#include <set>
using namespace std;
int main() {
    std::set<int> set1 = {1, 3, 5, 7, 9};
    std::set<int> set2 = {2, 4, 6, 8, 10};

    // Display initial set2
    std::cout << "Initial set2: ";
    for (auto elem : set2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
//lower_bound() :returns an iterator to the first element not less than the given key
   // Erase elements in a range
    auto lower = set2.lower_bound(4);
//upper_bound() :returns an iterator to the first element greater than the given key
    auto higher = set2.upper_bound(8);
    cout<<"lower <<"<<*lower<<" "<<"Higher"<<*higher<<endl;
    set2.erase(lower, higher);

    // Display set2 after erasing
    std::cout << "set2 after erase: ";
    for (auto elem : set2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

   // Merge set2 into set1 //1, 3, 5, 7, 9
    set1.merge(set2); // set 2: 2 10

    // Display set1 after merge
    std::cout << "set1: ";
    for (auto elem : set1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Display set2 after merge
    std::cout << "set2: ";
    for (auto elem : set2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

