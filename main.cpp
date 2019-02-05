#include <iostream>

using namespace std;

long multiply(int i, int j)
{
    return i * j;
}

template <class T>
typename T::multiplication_result multiply(T t1, T t2)
{
    return t1 * t2;
}

struct A
{
    char c;
    int a;
    long b;
};

union B
{
    int a;
    long b;
    char c;
};

int main(void)
{
    cout << sizeof(void*) << endl;
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(char) << endl;

    multiply(4, 5);
}
