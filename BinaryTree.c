#include <stdio.h>
#include <stdlib.h>

#define COUNT 5

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;

void print_nodes(node *root)
{
    if (!root) return;
    printf("%d ", root->value);
    print_nodes(root->left);
    print_nodes(root->right);
}

node *create_node(int value, node *left, node *right)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->left = left;
    new_node->right = right;

    return new_node;
}

node *place_new_node(node *root, node **new_node, int value)
{
    if (!root)
    {
        root = *new_node;
        return root;
    }

    if (value <= root->value)
    {
        if (!root->left)
        {
            root->left = *new_node;
            return root;
        }
        else place_new_node(root->left, new_node, value);
    }
    else if (value > root->value) {
        if (!root->right)
        {
            root->right = *new_node;
            return root;
        }
        else place_new_node(root->right, new_node, value);
    }

    return root;
}

node *add_node(node *root, int value)
{
    node *new_node = create_node(value, NULL, NULL);
    root = place_new_node(root, &new_node, value);
    return root;
}

int get_max(int x, int y)
{
    if (x >= y) return x;
    else return y;
}

int find_value(node *root, int value)
{
    if (!root) return -1;
    if (value == root->value) return 1;
    else if (value < root->value) return find_value(root->left, value);
    else return find_value(root->right, value);
}

int find_height(node *root)
{
    if (!root) return -1;
    int left_height = find_height(root->left);
    int right_height = find_height(root->right);
    return get_max(left_height, right_height) + 1;
}

void print2d_overload(struct node *root, int space)
{
    if (root == NULL) return;
    space += COUNT;
    print2d(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n", root->value);
    print2d(root->left, space);
}

void print2d(struct node *root)
{
    print2d(root, 0);
}

int main()
{
    node *root = NULL;
    // int values[] = {8, 12, 11, 16, 14, 13, 14, 17, 10, 15, 2, 1, 3, 0, 4, 5, 7, 18, 6, 9};
    int values[] = {6, 14, 13, 2, 1, 3, 0, 4};
    int size = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < size; ++i) root = add_node(root, values[i]);

    print_nodes(root);
    printf("\n");
    char *find_result = (find_value(root, 15)) ? "Number found.\n" : "Number not found.\n";
    printf("%s", find_result);
    printf("Depth of tree: %d\n", find_height(root));

    return 0;
}
