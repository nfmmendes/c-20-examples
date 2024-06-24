#include <iostream>
#include <concepts>
#include <type_traits>
#include <vector>
#include <functional>
using std::cout;
using std::endl;
using std::is_convertible_v;
using std::vector;

template <class T>
concept Container = requires(T &value) {
    value.begin();
    value.end();
    value.size();
};

template <typename T, typename Arg>
concept Callable = requires(T a, Arg arg) {
    {
        a(arg)
    } -> std::same_as<void>;
};

template <class... T>
auto transformation(T &&...operations)
{
    return [&operations...]<class D>
        requires Container<D> &&
                 (Callable<T, typename std::remove_reference_t<D>::value_type> && ...)
    (D &&data)
    {
        for (auto &value : data)
        {
            (operations(value), ...);
        }
        cout << endl;
    };
};

int main()
{
    std::function<void(int &)> multiplyBy2 = [](int &value)
    { value *= 2; };

    std::function<void(int &)> sum3 = [](int &value)
    { value += 3; };

    std::function<void(int &)> print = [](int &value)
    {
        cout << value << " ";
    };

    auto result = transformation(multiplyBy2, sum3, print);

    result(vector<int>{1, 2, 3, 4, 5});
    result(vector<int>{-2, 4, 6, 7, 0});

    return 0;
}