#include <iostream>
using namespace std;
int& func_ref(int a)
{
    static int value = a;
    return value;
}

// Overloaded functions
void func(int &a)
{
    cout << "lvalue reference called (lvalue reference)\n";
}

void func(const int &a)
{
    cout << "const lvalue reference called\n";
}

void func(int &&a)
{
    cout << "r-value reference called \n";
}

int main()
{
    int x = 11;
    int &l1 = x;
    cout << "l1 = " << l1 << endl;

    int &l2 = func_ref(x);
    cout << "l2 = " << l2 << endl;
    int &&r1 = 111;
    cout << "r1 = " << r1 << endl;

    func(x);      
    func(l1);      
    func(10);       
    func(r1);       
    const int c = 20;
    func(c);    

    return 0;
}

