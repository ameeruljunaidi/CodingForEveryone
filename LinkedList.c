#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

node *createNode(int val, node *next);
void printLinkedList(node *head);
void pushFront(node **head, int val);
void pushFrontAll(node **head, int values[], int size);
void pushBack(node **head, int val);
void clearLinkedList(node *head);
void reverseLinkedList(node **head);
node *getPointerToElement(node *head, int at);
int getElement(node *head, int at);
node *copyLinkedList(node *toCopy);
node *mergeLinkedList(node *left, node *right);
node *mergeSortLinkedList(node *head);
void testLinkedList();

/**
 * Function to initialize a linked list
 *
 * @param val is the value to initialize the linked list with
 * @param next the is the next node
 * @return the pointer to the new node
 */
node *createNode(int val, node *next)
{
    node *new = (node *) malloc(sizeof(node));
    new->value = val;
    new->next = next;

    return new;
}

/**
 * Helper function to print all values in a linked list
 *
 * @param head the pointer to the head of the linked list
 */
void printLinkedList(node *head)
{
    node *pointer = head;

    while (pointer)
    {
        printf("%d ", pointer->value);
        pointer = pointer->next;
    }

    printf("\n");
}

/**
 * Add a node to the front of the linked list
 *
 * @param head is the pointer to the head of the list
 * @param val the value to insert into the node
 */
void pushFront(node **head, int val)
{
    node *new = createNode(val, *head);
    *head = new;
}

/**
 * Given a list of integers, create a node for each and add to front of linked list
 *
 * @param head the pointer to the head of linked list to add the node to
 * @param values is the array containing all the integers
 * @param size the size of the array that contains all the integers
 */
void pushFrontAll(node **head, int values[], int size)
{
    for (int i = 0; i < size; i++) pushFront(head, values[i]);
}

/**
 * Add a new node with a value at the end of the linked list
 * @param head the pointer to the head of the linked list
 * @param val the value to insert into the linked list
 */
void pushBack(node **head, int val)
{
    node *new = createNode(val, NULL);
    node *pointer = *head;

    if (*head == NULL)
    {
        *head = new;
        return;
    }

    while (pointer->next != NULL) pointer = pointer->next;
    pointer->next = new;
}

void clearLinkedList(node *head)
{
    node *pointer = head;
    node *current = NULL;

    while (pointer != NULL)
    {
        current = pointer;
        pointer = pointer->next;

        free(current);
    }
}

void reverseLinkedList(node **head)
{
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

node *getPointerToElement(node *head, int at)
{
    node *pointer = head;
    for (int i = 0; i < at; i++) pointer = pointer->next;

    return pointer;
}

int getElement(node *head, int at)
{
    return getPointerToElement(head, at)->value;
}

int getLinkedListSize(node *head)
{
    int count = 0;

    if (head == NULL) return count;

    node *current = head;
    count++;

    while (current->next != NULL)
    {
        current = current->next;
        count++;
    }

    return count;
}

node *copyLinkedList(node *toCopy)
{
    node *ret = NULL;
    node *copier = toCopy;

    while (copier != NULL)
    {
        pushBack(&ret, copier->value);
        copier = copier->next;
    }

    return ret;
}

node *mergeLinkedList(node *left, node *right)
{
    node *current = createNode(0, NULL);
    node *temp = current;

    while (left && right)
    {
        if (left->value <= right->value)
        {
            current->next = left;
            left = left->next;
        } else
        {
            current->next = right;
            right = right->next;
        }

        current = current->next;
    }

    if (left) current->next = left;
    if (right) current->next = right;

    node *ret = temp->next;
    free(temp);

    return ret;
}

node *mergeSortLinkedList(node *head)
{
    if (head == NULL || head->next == NULL) return head;

    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;

    return mergeLinkedList(mergeSortLinkedList(head), mergeSortLinkedList(fast));
}

void testLinkedList()
{
    node *head = NULL;

    int numbers[] = {4, 0, 2, 3, 1, 5, 8, 6, 7, 15, 14, 13, 11, 12, 10, 9};
    int size = sizeof(numbers) / sizeof(int);

    pushFrontAll(&head, numbers, size);
    pushBack(&head, 16);
    reverseLinkedList(&head);
    printf("Linked list: ");
    printLinkedList(head);

    int findAt = 4;
    node *fourthElement = getPointerToElement(head, findAt);
    printf("Element at index %d is %d\n", findAt, fourthElement->value);
    printf("Element at index %d is %d\n", findAt, getElement(head, findAt));

    printf("Size of linked list is %d, similar to %d\n", getLinkedListSize(head), size);

    head = mergeSortLinkedList(head);
    printLinkedList(head);

    clearLinkedList(head);
}

int main()
{
    return 0;
}