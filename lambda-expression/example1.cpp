#include <iostream>
using std::cout;
using std::endl;

int main()
{
    auto print = []<typename T>(T value)
    { cout << value << endl; };

    print(5);
    print("Hello");
    print(5.4);
    print(false);

    return 0;
}