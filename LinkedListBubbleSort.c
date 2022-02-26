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
        printf("%d ", head->value);
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
{
    for (int i = 0; i < size; ++i) push_front(head, values[i]);
}

node *get_node(node *head, int index)
{
    for (int i = 0; i < index; ++i)
    {
        head = head->next;
    }

    return head;
}

void swap(node **head, node *a, node *b, node *c, node *d)
{
    // Swapping b and c
    // n, 1, 2, 3 -> start is null
    // a, b, c, d
    // 0, 1, 2, n -> end is null
    // a, b, c, d
    c->next = b;
    b->next = d;
    if (!a) *head = c;
    else a->next = c;
}

int sort_pass(node **head)
{
    node *a = NULL;
    node *b = *head;
    node *c = (*head)->next;
    node *d = (*head)->next->next;

    int flag = 0;
    while (c)
    {
        if (b->value > c->value) // Comparison, how to sort?
        {
            swap(head, a, b, c, d);
            ++flag;
        }
        a = b;
        b = c;
        c = d;
        if (!d) continue;
        else d = d->next;
    }
    return flag;
}

void sort(node **head)
{
    while (sort_pass(head));
}


void test()
{
    node *head = NULL;
    int values[] = {4, 5, 3, 2, 0, 1};
    int size = sizeof(values) / sizeof(values[0]);
    push_front_all(&head, values, size);
    printf("Original list: ");
    print_node(head);
    printf("Ordered list: ");
    sort(&head);
    print_node(head);
}

int main()
{
    test();
    return 0;
}
