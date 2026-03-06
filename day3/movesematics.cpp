#include <iostream>
using namespace std;

class emp
{
    int id;
    int rank;

public:
    emp(int i = 0, int r = 0) : id(i), rank(r) {}
    emp(const emp&) = delete;
    emp& operator=(const emp&) = delete;
    emp(emp&& other) noexcept
    {
        cout << "Move constructor\n";
        id = other.id;
        rank = other.rank;

        other.id = 0;
        other.rank = -1;
    }
    emp& operator=(emp&& other) noexcept
    {
        cout << "Move assignment operator\n";
        if (this != &other)
        {
            id = other.id;
            rank = other.rank;

            other.id = 0;
            other.rank = -1;
        }
        return *this;
    }

    void display() const
    {
        cout << "id = " << id << ", rank = " << rank << endl;
    }
};

emp func(int id, int p)
{
    emp obj(id, p);
    return obj;
}

int main()
{
    emp obj1(10, 1);
    obj1.display();
    emp obj2 = func(20, 2);
    obj2.display();
    emp obj3;
    obj3 = func(30, 3);
    obj3.display();

    return 0;
}

