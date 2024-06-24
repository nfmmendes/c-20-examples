#include <iostream>
#include <concepts>
using std::cout;
using std::endl;
using std::floating_point;
using std::integral;
using std::is_unsigned;

int main()
{
    auto integerInverse = []<std::integral T>(T &&x) -> double
    {
        cout << "Calling integral version with value " << x << endl;
        return 1.0 / x;
    };

    auto floatingInverse = []<floating_point T>(T &&x) -> double
    {
        cout << "Calling floating version with value " << x << endl;
        return 1.0 / x;
    };

    auto unsignedInverse = []<typename T>
        requires is_unsigned<T>::value
    (T x) -> double
    {
        cout << "Calling unsigned version with value " << x << endl;
        return 1.0 / x;
    };

    cout << integerInverse(5) << endl;
    cout << integerInverse(-5) << endl;
    // cout << integerInverse(5.0) << endl; // does not compile
    cout << floatingInverse(5.2) << endl;
    cout << floatingInverse(-5.2) << endl;
    // cout << floatingInverse(5) << endl;  // does not compile

    unsigned int a = 5;
    int b = -5;
    cout << unsignedInverse(a) << endl;
    // cout << unsignedInverse(b) << endl; // does not compile

    return 0;
}