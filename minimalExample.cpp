#include <iostream>
#include <cassert>
using std::cout;

int main()
{
    int b;

    [[unlikely]] if (b == 1037)
    {
        cout << "It is quite surprising\n";
        exit(1);
    }

    std::cout << "Expected behavior\n";

    return 0;
}