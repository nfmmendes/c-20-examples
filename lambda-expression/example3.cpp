#include <iostream>
using std::cout;
using std::endl;

class A
{
    int value = 5;

public:
    void printSomething()
    {
        //  warning: implicit capture of 'this' via '[=]' is deprecated in C++20 [-Wdeprecated]
        /*
        auto oldStyle = [=]()
        {
            cout << "Value is: " << value << endl;
        };
        */
        auto newStyle = [this]()
        {
            cout << "Value is: " << value << endl;
        };
    }
};

int main()
{
    A a;
    a.printSomething();

    return 0;
}