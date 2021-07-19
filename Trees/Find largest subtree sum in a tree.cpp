// C++ program to find largest subtree
// sum in a given binary tree.
#include <bits/stdc++.h>
using namespace std;
 
// Structure of a tree node.
struct Node {
    int data;
    Node *left, *right;
};
 
// Function to create new tree node.
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

int solve(Node* node, int &maxSum){
        
    if(node == NULL){
        return 0;
    }
        
    int l = solve(node -> left, maxSum);
    int r = solve(node -> right, maxSum);
        
    maxSum = max(maxSum, l + r + node -> data);
    return l + r + node -> data;
}
int findLargestSubtreeSum(Node *node)
{
    int maxSum = INT_MIN;
    solve(node,maxSum);
    return maxSum;
}
 
// Driver function
int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
 
    Node* root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);
 
    cout << findLargestSubtreeSum(root);
    return 0;
}
