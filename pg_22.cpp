#include <iostream>
using namespace std;

class Rectangle
{
    int length = 0;
    int breadth = 0;

public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }
    void changeLength(int l)
    {
        length = 20;
    }
};

int main()
{
    Rectangle r(10, 5);
    cout << r.area() << endl;
    r.changeLength(20);
    cout << r.area() << endl;
    Rectangle r2 = r;   //copy constructor
    cout << r2.area() << endl;
}