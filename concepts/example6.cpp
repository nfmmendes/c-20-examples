#include <iostream>
#include <concepts>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <array>
using std::array;
using std::cout;
using std::deque;
using std::endl;
using std::integral;
using std::list;
using std::map;
using std::queue;
using std::random_access_iterator;
using std::set;
using std::stack;
using std::string;
using std::vector;

template <class T>
// This is a concept that checks if the type T is a container that can be indexed with an integer and allows random access.
concept IntegerIndexedRandomAccessContainer = requires(T &t) {
    // This test if the container has a value_type member and if it is equals to T.
    std::is_same<typename T::value_type, decltype(t)>::value;

    // Check the subscript operator existence and its return type.
    {
        t[int{}]
    } -> std::convertible_to<typename T::value_type>;

    // Check if the container has a begin member function and if it returns a random access iterator.
    {
        t.begin()
    } -> random_access_iterator;
};

template <class T>
bool isIntegerIndexedContainer(T object)
{
    if constexpr (IntegerIndexedRandomAccessContainer<T>)
        return true;
    return false;
}

int main()
{
    cout << "Checking container definition with concept " << endl;
    cout << "Int variable: " << isIntegerIndexedContainer(4) << endl;
    cout << "Int Vector: " << isIntegerIndexedContainer(vector<int>{1, 2, 3}) << endl;
    cout << "String: " << isIntegerIndexedContainer(string{"Hello"}) << endl;
    cout << "Int std::array: " << isIntegerIndexedContainer(array<int, 3>{1, 2, 3}) << endl;
    cout << "Int set: " << isIntegerIndexedContainer(set<int>{1, 2, 3}) << endl;
    cout << "Int map: " << isIntegerIndexedContainer(map<int, string>{{1, "one"}, {2, "two"}}) << endl;
    cout << "Int deque: " << isIntegerIndexedContainer(deque<int>{1, 2, 3}) << endl;
    cout << "Int list: " << isIntegerIndexedContainer(list<int>{1, 2, 3}) << endl;
    cout << "Int stack: " << isIntegerIndexedContainer(stack<int>{}) << endl;

    return 0;
}
