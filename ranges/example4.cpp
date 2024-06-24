#include <iostream>
#include <vector>
#include <ranges>
#include <string>
using std::cout;
using std::string;
using std::to_string;
using std::vector;
using std::ranges::views::transform;

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

    for (auto n : twiceSquareAndName)
        cout << n.name << ", the double: " << n.twice << " the square: " << n.square << "\n";

    return 0;
}