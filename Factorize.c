#include <stdio.h>

void factorize(int number, int increment)
{
    if (number == 1) return;

    if (number % increment == 0)
    {
        printf("%d ", increment);
        return factorize(number / increment, increment);
    }

    return factorize(number, increment + 1);
}

int main()
{
    factorize(75, 2);
    printf("\n");

    return 0;
}
