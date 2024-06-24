#include <iostream>
#include <concepts>
#include <vector>
#include <string>
#include <memory>
using std::copyable;
using std::cout;
using std::endl;
using std::make_shared;
using std::make_unique;
using std::movable;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;

class A
{
public:
    A()
    {
        cout << "A default constructor" << endl;
    }
};

class B
{
public:
    B(int x)
    {
        cout << "B constructor with value " << x << endl;
    }

    B(B &&other)
    {
    }

    B &operator=(B &&other)
    {
        return *this;
    };
};

template <class T>
    requires std::movable<T>
void print(T &obj)
{
    cout << "The type " << typeid(T).name() << " is moveable " << endl;
}

template <class T>
    requires std::copyable<T>
void print(T &obj)
{
    cout << "The type " << typeid(T).name() << " is copyable " << endl;
}

int main()
{
    int a;
    string b;
    vector<int> c;
    unique_ptr<int> d = make_unique<int>(4);
    shared_ptr<int> e = make_shared<int>(5);
    A objA;
    B objB(5);

    print(a);
    print(b);
    print(c);
    print(d);
    print(e);
    print(objA);
    print(objB);

    return 0;
}