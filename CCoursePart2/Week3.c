#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utime.h>

typedef struct list
{
    int value;
    struct list *next;
} list;

// prototypes
void print_list(list *head);           // utility function to print all the values in the linked list
void push_back(list *head, int value); // utility function to push a number into the back of the linked list
int swap(list *left, list *right);     // utility function to swap the value of two adjacent element
void sort_list(list *head);            // function to sort the linked list given a pointer to start of the linked list

int main(void)
{
    // seed for random numbers
    time_t t;
    srand((unsigned)time(&t));

    // initialize the linked list
    list *head = malloc(sizeof(list));

    // if somehow malloc failed return 1
    if (head == null)
    {
        return 1;
    }

    // push a random number between 1 and 100 onto the back of the linked list
    for (int i = 0; i < 100; i++)
    {
        push_back(head, rand() % 100);
    }

    // print the unsorted list
    printf("unsorted list: ");
    print_list(head);

    // sort the list
    sort_list(head);

    // print the sorted list
    printf("sorted list: ");
    print_list(head);

    return 0;
}

void print_list(list *head) // utility function to print all the values in the linked list
{
    list *current = head; // initialize a current pointer that points to the head of the linked list

    while (current != null) // traverse through the linked list whilst the current node is not null
    {
        printf("%d ", current->value); // print the value of the current node if it is not null
        current = current->next;       // move the current pointer to point to the next node
    }

    printf("\n");
}

void push_back(list *head, int value) // utility function to push a number into the back of the linked list
{
    // not that this is not the most efficient way to add a value to the linked list
    // this is because we have to traverse the whole list and get to the very end before we can add a value
    // this means that adding an element to the linked list would take o(n) time complexity
    // a better way to do this is to add the element at the start of the linked list
    // this way, it would have a time complexity of o(1)

    list *current = head;         // initialize a pointer that points to the head of the linked list
    while (current->next != null) // traverse through the whole linked list, if next pointer is not null, go there
    {
        current = current->next;
    }

    current->next = (list *)malloc(sizeof(list)); // allocate a new memory location for the new node
    current->next->value = value;                 // assign the value to the newly created node
    current->next->next = null;                   // mark the next as null
}

int swap(list *left, list *right) // utility function to swap the value of two adjacent element
{
    int temp = left->value;     // temporarily store the value of the left element
    left->value = right->value; // left node will take the value of the right node
    right->value = temp;        // right value will then take the value of the temporarily stored

    return 1; // returns 1 to indicate that something was swapped
}

void sort_list(list *head) // function to sort the linked list given a pointer to start of the linked list
{
    if (head == null) // if the head of the linked list points to a null linked list, then return the function
    {
        return;
    }

    int swapped;               // this is a bool to check if anything was swapped
    list *current_node = head; // initialize a pointer that points to the head of the linked list

    do // keep going through the linked list from start if there is any element that was swapped
    {
        swapped = 0;         // start from fresh, nothing has been swapped yet
        current_node = head; // reset the current node to the head of the linked list

        while (current_node->next != null) // while the next node is not a null (while there is a next value)
        {
            if (current_node->value > current_node->next->value) // if the next value is smaller
            {
                swapped = swap(current_node, current_node->next); // then swap, and change the swapped bool to true
            }

            current_node = current_node->next; // move the pointer to the next element
        }
    } while (swapped);
}
