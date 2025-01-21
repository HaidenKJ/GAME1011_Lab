// friend class - a class whose members have access to the private or protected members of another class:
#include <iostream>
using namespace std;

//declare Square class here - void convert needs to know that such a class exists
class Square;

class Rectangle
{
public:
    int area()
    {
        return (width * height);
    }
    void convert(Square sq);
private:
    int width, height;
};

class Square
{
    friend class Rectangle;
public:
    Square(int s) : side(s) {}
private:
    int side;
};

void Rectangle::convert(Square sq)
{
    width = sq.side;
    height = sq.side;
}

//int main()
//{
//    Rectangle rect;
//    Square sqr(4);
//    rect.convert(sqr);
//    cout << rect.area();
//    return 0;
//}