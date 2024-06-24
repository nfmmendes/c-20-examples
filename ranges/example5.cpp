#include <iostream>
#include <type_traits>
#include <iterator>
#include <vector>
#include <ranges>
#include <string>
#include <algorithm>
#include <concepts>
using std::convertible_to;
using std::cout;
using std::ostream;
using std::ostream_iterator;
using std::string;
using std::to_string;
using std::vector;
using std::ranges::copy;
using std::ranges::views::transform;

template <class T>
concept StrangeType = requires(T &t) {
    {
        t.name
    } -> std::convertible_to<string>;
    {
        t.twice
    } -> std::convertible_to<int>;
    {
        t.square
    } -> std::convertible_to<int>;
};

template <class T>
    requires StrangeType<T>
ostream &operator<<(ostream &os, const T &n)
{
    return os << n.name << ", the double: " << n.twice << " the square: " << n.square;
};

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto twiceSquareAndName = numbers | transform([](int n)
                                                  {
                                                    struct {
                                                        string name;
                                                        int twice;
                                                        int square;
                                                    }
                                                    obj{"number: " + to_string(n), 2*n, n*n};
                                                    return obj; });

    typedef decltype(twiceSquareAndName[0]) T;
    copy(twiceSquareAndName, ostream_iterator<T>(cout, "\n-----------------------\n"));

    return 0;
}
