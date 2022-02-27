#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char *name;
    int age;
    struct node *next;
} node;

node *init_node(int age, char *name, node *next)
{
    node *new_node = (node *) malloc(sizeof(node));
    new_node->name = name;
    new_node->age = age;
    new_node->next = next;
    return new_node;
}

void push_front(node **head, char *name, int value)
{ *head = init_node(value, name, *head); }

void push_front_all(node **head, int values[], int size)
{ for (int i = 0; i < size; ++i) push_front(head, "", values[i]); }

void swap(node **head, node *a, node *b, node *c, node *d)
{
    if (!a) *head = c;
    else a->next = c;
    b->next = d;
    c->next = b;
}

int ascending_age(node *b, node *c)
{
    if (b->age > c->age) return 1;
    else return 0;
}

int descending_age(node *b, node *c)
{
    if (b->age < c->age) return 1;
    else return 0;
}

int alphabetically(node *b, node *c)
{
    int i = 0, j = 0;
    while (b->name[i] != '\0' && c->name[j] != '\0')
    {
        if (b->name[i] > c->name[i]) return 1;
        else if (b->name[i] < c->name[i]) return 0;
        else ++i, ++j;
    }
    if (ascending_age(b, c)) return 1;
    return 0;
}

int single_pass(node **head, int (*compare)(node *, node *))
{
    node *a = NULL, *b = *head, *c = (*head)->next, *d = (*head)->next->next;
    int check = 0;
    while (c)
    {
        if (compare(b, c))
        {
            swap(head, a, b, c, d);
            a = c, b = b, c = d, ++check;
        } else
        {
            a = b, b = c, c = d;
        }
        d = (!d) ? d : d->next;
    }
    return check;
}

void sort(node **head, int (*compare)(node *, node *))
{ while (single_pass(head, compare)); }

void print_node(node *head, int name)
{
    while (head)
    {
        if (name) printf("{ %s, %.2d } ", head->name, head->age);
        else printf("%.2d ", head->age);
        head = head->next;
    }
    printf("\n");
}

void free_nodes(node *head)
{
    node *current = head, *next = head->next;
    while (next)
    {
        free(current);
        current = next;
        next = next->next;
    }
}

void test1()
{
    node *head = NULL;
    int values[] = {4, 5, 3, 2, 0, 1};
    int size = sizeof(values) / sizeof(values[0]);
    push_front_all(&head, values, size);
    printf("Original list: ");
    print_node(head, 0);
    printf("Ordered ascending:  ");
    sort(&head, ascending_age);
    print_node(head, 0);
    free_nodes(head);
    printf("--------------------------------------------------------------\n");
}

void test2()
{
    node *head = NULL;
    int values[] = {4, 6, 123, 52, 3, 252, 55, 34, 32, 1, 34, 5, 5, 35, 2, 235, 2, 5, 6, 6, 6};
    int size = sizeof(values) / sizeof(values[0]);
    push_front_all(&head, values, size);
    printf("Original list: ");
    print_node(head, 0);
    printf("Ordered descending:  ");
    sort(&head, descending_age);
    print_node(head, 0);
    free_nodes(head);
    printf("--------------------------------------------------------------\n");
}

void test3()
{
    node *head = NULL;
    push_front(&head, "Jesus", 19);
    push_front(&head, "Jesus", 38);
    push_front(&head, "Jesus", 25);
    push_front(&head, "Eric", 24);
    push_front(&head, "Derek", 16);
    push_front(&head, "Antoine", 23);
    printf("Original list: ");
    print_node(head, 1);
    // sort(&head, ascending_age);
    // printf("Sorted ascending age: ");
    // print_node(head, 1);
    sort(&head, alphabetically);
    printf("Sorted alphabetically: ");
    print_node(head, 1);
    printf("--------------------------------------------------------------\n");
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}

// Output:
//
// Original list: 01 00 02 03 05 04
// Ordered list:  00 01 02 03 04 05
// Original list: 06 06 06 05 02 235 02 35 05 05 34 01 32 34 55 252 03 52 123 06 04
// Ordered list:  01 02 02 03 04 05 05 05 06 06 06 06 32 34 34 35 52 55 123 235 252
