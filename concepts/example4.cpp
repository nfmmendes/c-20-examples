#include <iostream>
using std::cout;
using std::is_floating_point;

template <class T1, class T2>
concept FloatPointOperators = is_floating_point<T1>::value && is_floating_point<T2>::value;

template <class T>
concept Arithmetic = std::is_arithmetic<T>::value;

int main()
{
    int a{4};
    int b{4};
    double c{4.000002};
    double d{4.000013};

    auto isEqual = [](Arithmetic auto x, Arithmetic auto y)
    {
        if constexpr (FloatPointOperators<decltype(x), decltype(y)>)
        {
            cout << "Comparing two floats\n";
            return std::abs(x - y) < 0.00001;
        }
        else
        {
            cout << "Not comparing two floats\n";
            return x == y;
        }
    };

    isEqual(a, b);
    isEqual(c, d);
    isEqual(a, c);
    isEqual(b, d);

    return 0;
}