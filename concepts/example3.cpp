#include <iostream>
#include <concepts>
using std::cout;
using std::endl;
using std::is_floating_point;

template <class T1, class T2>
concept NonTrunckedResult = is_floating_point<T1>::value || is_floating_point<T2>::value;

template <class T1, class T2>
    requires NonTrunckedResult<T1, T2>
double floatingPointMultiplication(T1 first, T2 second)
{
    return first * second;
}

int main()
{
    cout << floatingPointMultiplication(3.5, 2) << endl;
    cout << floatingPointMultiplication(3, 2.5) << endl;
    // This will not compile
    // cout << floatingPointMultiplication(3, 2) << endl;
    return 0;
}