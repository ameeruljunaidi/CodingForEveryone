#include <stdio.h>

void factorize(int n)
{
    int number = n;
    int divisor = 2;

    while (number != 1)
    {
        if (number % divisor == 0)
        {
            printf("%d ", divisor);
            number /= divisor;
        }
        else divisor++;
    }
}

int main()
{
    factorize(50);
}