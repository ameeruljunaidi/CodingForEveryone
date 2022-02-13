#include <iostream>

struct Rectangle
{
    int length;
    int width;

    Rectangle(int l, int w)
    {
        this->length = l;
        this->width = w;
    }

    int getArea()
    {
        return this->length * this->width;
    }
};

int main()
{
    Rectangle r(2, 2);

    std::cout << r.getArea() << '\n';

    return 0;
}