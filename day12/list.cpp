#include<list>
#include<iostream>
int main()
{
    std::list<int> l1 = {1,2,3};
    std::list<int> l2 = {10,20};
    auto it = l2.begin();
    advance(it,1);
    l1.splice(l1.begin(), l2,l2.begin(),l2.end());
    for (int x : l1)
        std::cout << x <<" ";
}
