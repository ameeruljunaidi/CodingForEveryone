#include <stdio.h>

void penisify(char s[])
{
    char p[] = "penis";
    int flag = 0;
    int x = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == 'o') flag = 1;

        if (flag)
        {
            if (p[x] == '\0')
            {
                flag = 0;
                x = 0;
            }

            s[i] = p[x];
            x++;
        }
    }
}

int main()
{
    char s[] = "mother fucker";
    penisify(s);
    printf("%s\n", s);
}