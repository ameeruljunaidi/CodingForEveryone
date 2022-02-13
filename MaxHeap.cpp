#include <iostream>

using std::cout;

int add(int x)
{
    if (x == 0) return 0;
    return 1 + add(x - 1);
}

int main()
{
    cout << add(8) << "\n";
}