#include <iostream>
using namespace std;

class Led
{
    bool ledState;
    bool switchState;

public:
    // Constructor
    Led(bool led = false, bool sw = false)
        : ledState(led), switchState(sw) {}

    void setSwitch(bool state)
    {
        if (switchState == state)
        {
            cout << "Switch is already " << (state ? "ON" : "OFF") << endl;
            return;
        }

        switchState = state;
        cout << "Switch turned " << (state ? "ON" : "OFF") << endl;
    }

    void setLed(bool state)
    {
        if (ledState == state)
        {
            cout << "LED is already " << (state ? "ON" : "OFF") << endl;
            return;
        }

        ledState = state;
        cout << "LED turned " << (state ? "ON" : "OFF") << endl;
    }

    void operator()(bool led)
    {
        setLed(led);
    }

    void operator()(bool led, bool sw)
    {
        setSwitch(sw);
        setLed(led);
    }

    void display() const
    {
        cout << "Current Status -> "
             << "Switch: " << (switchState ? "ON" : "OFF")
             << ", LED: " << (ledState ? "ON" : "OFF") << endl;
    }
};

int main()
{
    Led obj;

    obj(true, false); 
    obj.display();

    obj(true);        
    obj(false, true);   
    obj.display();

    return 0;
}

