#include <iostream>
#include <concepts>
using std::cout;
using std::endl;

class A
{

public:
    void customPrint()
    {
        cout << "Print from class A\n";
    }
};

class B
{
public:
    void customPrint()
    {
        cout << "Print from class B\n";
    }
};

class C
{
public:
    void otherCustomPrint()
    {
        cout << "Print from class C\n";
    }
};

template <class T>
concept HasCustomPrint = requires(T value) {
    value.customPrint();
};

template <class T>
    requires HasCustomPrint<T>
void testPrint(T &object)
{
    object.customPrint();
}

int main()
{
    A a;
    B b;
    C c;

    testPrint(a);
    testPrint(b);
    // testPrint(c);

    return 0;
}