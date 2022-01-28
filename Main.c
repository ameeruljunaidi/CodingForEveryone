#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *create_node(int value, node *next)
{
    node *new = (node *)malloc(sizeof(node));
    new->value = value;
    new->next = next;

    return new;
}

void push_front(node **head, int value)
{
    node *new = create_node(value, *head);
    (*head) = new;
}

void push_all(node **head, int values[], int size)
{
    for (int i = 0; i < size; i++) push_front(head, values[i]);
}

void print_nodes(node *head)
{
    node *pointer = head;

    while (pointer != NULL)
    {
        printf("%d ", pointer->value);
        pointer = pointer->next;
    }
    printf("\n");
}

node *merge_list(node *left, node *right)
{
    node *head = create_node(0, NULL);
    node *pointer = head;

    while (left != NULL && right != NULL)
    {
        if (left->value < right->value)
        {
            pointer->next = left;
            left = left->next;
        }
        else
        {
            pointer->next = right;
            right = right->next;
        }

        pointer = pointer->next;
    }

    while (left != NULL)
    {
        pointer->next = left;
        left = left->next;
        pointer = pointer->next;
    }

    while (right != NULL)
    {
        pointer->next = right;
        right = right->next;
        pointer = pointer->next;
    }

    return head;
}

node *merge_sort(node *head)
{
    if (head == NULL || head->next == NULL) return head;

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *temp = slow->next;
    slow->next = NULL;

    return merge_list(merge_sort(head), merge_sort(temp));
}

void reverse_list(node **head)
{
    node *previous = NULL;
    node *current = *head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    (*head) = previous;
}

int main()
{
    node *head = NULL;
    int values[] = {1, 5, 2, 4, 3, 0};
    int size = sizeof(values) / sizeof(values[0]);
    push_all(&head, values, size);
    print_nodes(head);
    merge_sort(head);
    print_nodes(head);
    reverse_list(&head);
    print_nodes(head);

    return 0;
}