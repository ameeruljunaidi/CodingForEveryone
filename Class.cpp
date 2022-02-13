#include <iostream>

template<class T>
class Rectangle
{
private:
    T length;
    T width;
public:
    Rectangle();
    Rectangle(T length, T width);
    T getArea();
};

template<class T>
Rectangle<T>::Rectangle()
{
    this->width = 0;
    this->length = 0;
}

template<class T>
Rectangle<T>::Rectangle(T length, T width)
{
    this->length = length;
    this->width = width;
}

int main()
{
    return 0;
}