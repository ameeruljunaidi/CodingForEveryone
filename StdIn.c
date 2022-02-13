#include <stdio.h>
#include <stdlib.h>

char *get_word(char *sentence, int index)
{
    int count = -1;
    char *word = sentence;
    while (*sentence != '\0' && count != index)
    {
        if (*sentence == ' ' && ++count == index) break;
        else if (*sentence == ' ' && count != index) word = sentence + 1;
        sentence++;
    }

    int i, length = 0;
    for (char *p = word; *p != ' '; ++p) ++length;
    char *new_word = (char *) malloc(sizeof(char) * (length + 1));
    for (i = 0; i < length; i++) new_word[i] = word[i];
    new_word[i] = '\0';

    return new_word;
}

int main()
{
    char *s = "my name is bond, james bond";
    char *d = get_word(s, 4);
    printf("String is:%s", d);
    free(d);
    return 0;
}

