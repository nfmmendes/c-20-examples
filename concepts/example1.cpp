#include <iostream>
#include <concepts>
#include <string>
using std::cout;
using std::endl;
using std::integral;
using std::is_arithmetic;
using std::is_integral;
using std::string;

template <integral T>
void print(T t)
{
    cout << t << " is integral" << endl;
}

template <std::floating_point T>
void print(T t)
{
    cout << t << " is floating point" << endl;
}

int main()
{
    int a{1};
    double b = {2.0};
    string c = "Hello";

    if (is_integral<decltype(a)>::value)
        cout << "a is an integral type" << endl;

    [[unlikely]] if (is_integral<decltype(b)>::value)
        cout << "b is an integral type" << endl;

    if (is_arithmetic<decltype(a)>::value)
        cout << "b is an arithmetic type" << endl;
    if (is_arithmetic<decltype(b)>::value)
        cout << "b is an arithmetic type" << endl;
    [[unlikely]] if (is_arithmetic<decltype(c)>::value)
        cout << "c is a numeric type" << endl;

    print(a);
    print(b);

    return 0;
}