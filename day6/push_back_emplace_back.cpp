#include<vector>
#include<string>
#include<iostream>
struct Person {
std::string name;
int age;

Person(std::string n,int a) :name(n),age(a) {
        std::cout <<"Constructor\n";
    }

Person(const Person&) {
        std::cout <<"Copy constructor\n";
    }

Person(Person&&)noexcept {
        std::cout <<"Move constructor\n";
    }
};

int main() {
    std::vector<Person> v;

    std::cout <<"push_back:\n";
    v.push_back(Person("Alice",30)); // 1 2

    std::cout <<"\n1emplace_back:\n";
    v.emplace_back("Bob",25);
/*    std::cout <<"\n2emplace_back:\n";
     v.emplace_back("Sam",35);
      std::cout <<"\n3 emplace_back:\n";
     v.emplace_back("Joy",36);
     std::cout <<"4 emblace_back:\n";
      v.emplace_back("John",36); // cap =8 , ele =5
    //   v.emplace_back("Jovin",36); //constructor
    //  std::cout <<"push_back:\n";
     std::cout <<"push_back:\n";
     v.push_back(Person("Alvin",30)); //constru + mov
*/}


