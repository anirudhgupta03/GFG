#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}
void flatten(node* root, node* &prev, node* &head){
    
    if(root == NULL){
      return;
    }
    flatten(root->left,prev,head);
    if(prev == NULL){
      head = root;
      prev = root;
    }
    else{
      prev -> right = root;
      prev = root;
    }
    root -> left = NULL;
    flatten(root->right,prev,head);
}
int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
 
    node* prev = NULL, *head;
    flatten(root,prev,head);
    
    print(head);
    return 0;
}

//https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=2
//Flatten BST To A Sorted List
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int>* root, TreeNode<int>* &prev, TreeNode<int>* &head){
    
    if(root == NULL){
        return;
    }
    
    solve(root -> left, prev, head);
    if(prev == NULL){
        head = root;
    }
    else{
        prev -> right = root;
    }
    prev = root;
    prev -> left = NULL;
    solve(root -> right, prev, head);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* head, *prev = NULL;
    solve(root, prev, head);
    return head;
}
