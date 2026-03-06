#include <iostream>
using namespace std;

class student
{
    int roll_no;
    int *marks;

public:
    student(int r = 0, int m = 0) : roll_no(r), marks(new int(m)) {}

    ~student()
    {
        delete marks;
    }

    student(const student &other) : roll_no(other.roll_no), marks(new int(*other.marks))
    {
        cout << "Copy constructor called\n";
    }

    student& operator=(const student &other)
    {
        if (this != &other)
        {
            delete marks;        
            roll_no = other.roll_no;
            marks = new int(*other.marks); 
        }
        cout << "Copy assignment called\n";
        return *this;
    }

    void display() const
    {
        cout << "Roll No: " << roll_no << endl;
        cout << "Marks  : " << *marks << endl;
    }
};

int main()
{
    student s1(101, 85);
    student s2 = s1;
    s1.display();
    s2.display();
    student s3;
    s3 = s1;
    s3.display();

    return 0;
}

