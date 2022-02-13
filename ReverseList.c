#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *create_node(int value, node *next)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = next;

    return new_node;
}

node *push_front(node *head, int value)
{
    node *new_node = create_node(value, head);
    return new_node;
}

node *push_all_front(node *head, int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        head = push_front(head, numbers[i]);
    }
    return head;
}

void print_nodes(node *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void reverse_print_nodes(node *head)
{
    if (head == NULL) return;
    reverse_print_nodes(head->next);
    printf("%d ", head->value);
}

node *reverse_nodes(node *head)
{
    node *previous = NULL;
    node *current = head;
    node *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

int main()
{
    node *head = NULL;
    int numbers[] = {3, 2, 5, 1, 0, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    head = push_all_front(head, numbers, size);
    print_nodes(head);
    // reverse_print_nodes(head);
    head = reverse_nodes(head);
    print_nodes(head);
    // printf("\n");

    return 0;
}
