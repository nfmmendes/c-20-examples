#include <iostream>
#include <numeric>
#include <vector>
using std::cout;
using std::endl;
using std::floating_point;
using std::is_convertible_v;
using std::vector;

struct Point
{
    double x;
    double y;
};

template <class... T>
    requires(is_convertible_v<T, double> && ...)
auto filterByY(T... yValues)
{
    return [yValues...](const Point &point)
    {
        return ((point.y == yValues) || ...);
    };
}

void printFilter(auto &&points, auto &&filter)
{
    for (auto point : points)
    {
        if (filter(point))
        {
            cout << "Point: (" << point.x << ", " << point.y << ")\n";
        }
    }
    cout << "_______________________________________" << endl;
}

int main()
{
    const auto points = {Point{1, 2}, Point{3, 4}, Point{4, 2}, Point{8, 2},
                         Point{9, 5}, Point{12, 0}, Point{8, 3}, Point{6, 6}};

    auto pointFiter = filterByY(2.0, 3.0);
    printFilter(points, pointFiter);
    printFilter(points, filterByY(0.0, 5.0, -1, 6));

    vector<Point> extendedPoints{points};
    extendedPoints.insert(extendedPoints.end(), {Point{1, -2}, Point{0, 3}, Point{3, 1}, Point{1, 2},
                                                 Point{19, 0}, Point{1, 6}, Point{2, 3}});
    printFilter(extendedPoints, pointFiter);

    return 0;
}