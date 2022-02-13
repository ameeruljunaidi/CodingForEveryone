#include <iostream>

using std::cout;

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;

void insert_node(node **root, int value)
{
    node *newNode = new node();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (*root == nullptr) *root = newNode;
    else if (value < (*root)->value) insert_node(&(*root)->left, value);
    else if (value > (*root)->value) insert_node(&(*root)->right, value);
}

void insert_all(node **root, int values[], int size)
{
    for (int i = 0; i < size; i++) insert_node(root, values[i]);
}

void print_nodes(node *root)
{
    if (root == nullptr) return;

    cout << root->value << " ";
    print_nodes(root->left);
    print_nodes(root->right);
}

int binary_search(node *root, int value)
{
    if (root == nullptr) return -1;

    if (value == root->value) return 1;
    else if (value < root->value) return binary_search(root->left, value);
    else return binary_search(root->right, value);
}

int find_min(node *root)
{
    if (root->left == nullptr) return root->value;
    else return find_min(root->left);
}

int find_max(node *root)
{
    if (root->right == nullptr) return root->value;
    else return find_min(root->right);
}

int main()
{
    int values[] = {2, 4, 1, 29, 0};
    int size = sizeof(values) / sizeof(values[0]);

    node *root = nullptr;
    insert_all(&root, values, size);
    print_nodes(root);
    cout << "\n" << binary_search(root, 8) << "\n";
    cout << find_min(root) << " " << find_max(root) << "\n";

    return 0;
}