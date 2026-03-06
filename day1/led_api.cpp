#include <iostream>
using namespace std;

class Led
{
    bool status;  

public:
    Led(bool s = false) : status(s) {}

    void ledblink()
    {
        cout << "LED blink\n";
    }

    void ledtoggle()
    {
        status = !status;   // toggle status
        cout << "LED toggled\n";
    }

    void display() const
    {
        if (status)
            cout << "LED is ON\n";
        else
            cout << "LED is OFF\n";
    }
};

int main()
{
    Led obj(true);   

    obj.ledblink();
    obj.display();

    obj.ledtoggle(); 
    obj.display();

    return 0;
}

