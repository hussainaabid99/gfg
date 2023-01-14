// convert binary tree to doubly linked list
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        right = left = NULL;
    }
};

Node *BTToDLL(Node *root)
{
    if (root == NULL)
        return root;
    static Node *prev = NULL;
    Node *head = BTToDLL(root->left);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTToDLL(root->right);
    return head;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    return 0;
}