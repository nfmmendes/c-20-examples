#include <iostream>
#include <vector>
#include <iterator>
#include <ranges>
using std::cout;
using std::iterator;
using std::vector;
using std::ranges::subrange;

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Create a range from the vector
    auto numberRange = subrange(numbers.begin() + 1, numbers.end() - 2);

    for (int number : numberRange)
        cout << number << " ";

    return 0;
}