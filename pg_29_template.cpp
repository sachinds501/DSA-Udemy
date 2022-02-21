// Template class

#include <iostream>
using namespace std;

template <class T>

class Arithmatic
{
    T a;
    T b;

public:
    Arithmatic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmatic<T>::Arithmatic(T a, T b)
{
    this->a = a;
    this->b = b;
}
template <class T>
T Arithmatic<T>::add()
{
    return a + b;
};
template <class T>
T Arithmatic<T>::sub()
{
    return a - b;
};

int main()
{
    Arithmatic<int> A1(15, 3);

    cout << A1.add() << endl;
    cout << A1.sub() << endl;

    Arithmatic<float> A2(1.5, 3.3);

    cout << A2.add() << endl;
    cout << A2.sub() << endl;

    return 0;
}