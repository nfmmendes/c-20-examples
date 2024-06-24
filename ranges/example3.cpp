#include <iostream>
#include <vector>
#include <ranges>
#include <cmath>
using std::cout;
using std::vector;
using std::views::filter;

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto squared = numbers | filter([](int n)
                                    { return pow(static_cast<int>(sqrt(n)), 2) == n; });

    for (int n : squared)
        cout << n << " ";

    return 0;
}