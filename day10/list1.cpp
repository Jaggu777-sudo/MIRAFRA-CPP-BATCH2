#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void printList(const list<int>& lst)
{
    for (int val : lst)
        cout << val << " ";
    cout << endl;
}

int main()
{
    list<int> l1;          
    list<int> l2(5, 10);        
    list<int> l3 = {1, 2, 3, 4, 5};  

    cout << "Initial l3: ";
    printList(l3);
    l3.push_front(0);
    l3.push_back(6);
    cout << "After push_front & push_back: ";
    printList(l3);
    l3.pop_front();
    l3.pop_back();
    cout << "After pop_front & pop_back: ";
    printList(l3);
    cout << "Front element: " << l3.front() << endl;
    cout << "Back element: " << l3.back() << endl;

    auto it = l3.begin();
    advance(it, 2);
    l3.insert(it, 99);
    cout << "After insert: ";
    printList(l3);
    it = l3.begin();
    advance(it, 2);
    l3.erase(it);
    cout << "After erase: ";
    printList(l3);
    l1.remove(7);
    cout << "After remove(7): ";
    printList(l1);
    l3.remove_if([](int x) { return x % 2 == 0; });
    cout << "After remove_if (remove even): ";
    printList(l3);
    l3.reverse();
    cout << "After reverse: ";
    printList(l3);
    l3.sort();
    cout << "After sort: ";
    printList(l3);
    l3.push_back(5);
    l3.push_back(5);
    l3.unique();
    cout << "After unique: ";
    printList(l3);
    list<int> l4 = {1, 3, 5};
    list<int> l5 = {2, 4, 6};
    l4.merge(l5);
    cout << "After merge: ";
    printList(l4);
    list<int> l6 = {100, 200};
    l4.splice(l4.begin(), l6);
    cout << "After splice: ";
    printList(l4);
    l6.clear();
    cout << "Size of l6 after clear: " << l6.size() << endl;
    cout << "Is l6 empty? " << (l6.empty() ? "Yes" : "No") << endl;
    cout << "Size of l4: " << l4.size() << endl;

    return 0;
}

