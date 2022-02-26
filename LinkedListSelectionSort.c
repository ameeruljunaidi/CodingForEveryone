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

node *ascending(node *head)
{
    node *smallest = head;
    while (head)
    {
        if (head->value < smallest->value) smallest = head;
        head = head->next;
    }
    return smallest;
}

node *descending(node *head)
{
    node *largest = head;
    while (head)
    {
        if (head->value > largest->value) largest = head;
        head = head->next;
    }
    return largest;
}

node *extract_node(node **head, node *extract)
{
    node *previous = NULL;
    node *current = *head;
    node *next = NULL;
    while (current)
    {
        if (current == extract)
        {
            if (!previous) *head = current->next;
            else previous->next = current->next;
            current->next = NULL;
        }
        next = current->next;
        previous = current;
        current = next;
    }
    return extract;
}

void single_pass(node **head, node *(f)(node *))
{
    node *extracted = extract_node(head, f(*head));
    extracted->next = *head;
    *head = extracted;
}

void selection_sort(node **head, node *(f)(node *))
{
    node **current = head;
    while (*current)
    {
        single_pass(current, f);
        current = &(*current)->next;
    }
}

void test_extract()
{
    printf("Testing extract function\n");
    printf("------------------------\n");
    node *head = NULL;
    int values[] = {5, 2, 1, 0, 4, 3};
    int size = sizeof(values) / sizeof(values[0]);
    push_front_all(&head, values, size);
    printf("Original list:");
    print_node(head);
    node *smallest = ascending(head);
    node *extract = extract_node(&head, smallest);
    printf("Extracted: ");
    print_node(extract);
    printf("Remaining: ");
    print_node(head);
    printf("\n");
}

void test_single_pass()
{
    printf("Testing single pass function\n");
    printf("----------------------------\n");
    node *head = NULL;
    int values[] = {5, 2, 1, 0, 4, 3};
    int size = sizeof(values) / sizeof(values[0]);
    push_front_all(&head, values, size);
    printf("Original list: ");
    print_node(head);
    printf("After one pass ascending: ");
    single_pass(&head, ascending);
    print_node(head);
    printf("After one pass descending: ");
    single_pass(&head, descending);
    print_node(head);
    printf("\n");
}

void test_sort()
{
    printf("Testing sorting function\n");
    printf("------------------------\n");
    node *head = NULL;
    int values[] = {5, 2, 1, 0, 4, 3};
    int size = sizeof(values) / sizeof(values[0]);
    push_front_all(&head, values, size);
    printf("Original list: ");
    print_node(head);
    printf("After sort ascending: ");
    selection_sort(&head, ascending);
    print_node(head);
    printf("After sort ascending: ");
    selection_sort(&head, descending);
    print_node(head);
    free_nodes(head);
    printf("\n");
}

int main()
{
    test_extract();
    test_single_pass();
    test_sort();
    return 0;
}
