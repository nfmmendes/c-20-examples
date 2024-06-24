#include <iostream>
#include <vector>
#include <ranges>
using std::cout;
using std::vector;
using std::views::transform;

int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};

    // Use ranges to filter and transform the numbers
    auto doubledNumbers = numbers | transform([](int n)
                                              { return n * 2; });
    // Print the transformed numbers
    for (int n : doubledNumbers)
        cout << n << " ";

    return 0;
}