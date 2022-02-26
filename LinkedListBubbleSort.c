#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

void print_node(node *head)
{
    while (head)
    {
        printf("%.2d ", head->value);
        head = head->next;
    }
    printf("\n");
}

node *init_node(int value, node *next)
{
    node *new_node = (node *) malloc(sizeof(node));
    new_node->value = value;
    new_node->next = next;
    return new_node;
}

void free_nodes(node *head)
{
    node *current = head;
    node *next = head->next;

    while (next)
    {
        free(current);
        current = next;
        next = next->next;
    }
}

void push_front(node **head, int value)
{
    node *new_node = init_node(value, *head);
    *head = new_node;
}

void push_front_all(node **head, int values[], int size)
{ for (int i = 0; i < size; ++i) push_front(head, values[i]); }

void swap(node **head, node *a, node *b, node *c, node *d)
{
    if (!a) *head = c;
    else a->next = c;
    b->next = d;
    c->next = b;
}

int single_pass(node **head)
{
    node *a = NULL;
    node *b = *head;
    node *c = (*head)->next;
    node *d = (*head)->next->next;

    int check = 0;
    while (c)
    {
        if (b->value > c->value) // Comparison, how to sort?
        {
            swap(head, a, b, c, d);
            a = c, b = b, c = d, ++check;
        } else a = b, b = c, c = d;
        d = (!d) ? d : d->next;
    }
    return check;
}

void sort(node **head)
{ while (single_pass(head)); }


void test1()
{
    node *head = NULL;
    int values[] = {4, 5, 3, 2, 0, 1};
    int size = sizeof(values) / sizeof(values[0]);
    push_front_all(&head, values, size);
    printf("Original list: ");
    print_node(head);
    printf("Ordered list:  ");
    sort(&head);
    print_node(head);
    free_nodes(head);
}

void test2()
{
    node *head = NULL;
    int values[] = {4, 6, 123, 52, 3, 252, 55, 34, 32, 1, 34, 5, 5, 35, 2, 235, 2, 5, 6, 6, 6};
    int size = sizeof(values) / sizeof(values[0]);
    push_front_all(&head, values, size);
    printf("Original list: ");
    print_node(head);
    printf("Ordered list:  ");
    sort(&head);
    print_node(head);
    free_nodes(head);
}

int main()
{
    test1();
    test2();
    return 0;
}

// Output:
//
// Original list: 01 00 02 03 05 04
// Ordered list:  00 01 02 03 04 05
// Original list: 06 06 06 05 02 235 02 35 05 05 34 01 32 34 55 252 03 52 123 06 04
// Ordered list:  01 02 02 03 04 05 05 05 06 06 06 06 32 34 34 35 52 55 123 235 252
