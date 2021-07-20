#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
};
 
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}
 

void insertInBST(Node* &node, int data, Node* &succ)
{
   if(node == NULL){
       cout << "Hi" << endl;
      node = newNode(data); 
      return;
   }
   
   Node* temp = node;
   while(1){
      if(node -> data > data){
        succ = node;
        if(node -> left) node = node -> left;
        else{
          node -> left = newNode(data);
          break;
        }
      }
      else{
        if(node -> right) node = node -> right;
        else{
          node -> right = newNode(data);
          break;
        }
      }
   }
   node = temp;
}
 
void replace(int arr[], int n)
{
    Node* root = NULL;
 
    for (int i = n - 1; i >= 0; i--) {
        
        Node* succ = NULL;
      
        insertInBST(root, arr[i], succ);
 
        if (succ)
            arr[i] = succ->data;
        else // No inorder successor
            arr[i] = -1;
    }
}
 
// Driver Program to test above functions
int main()
{
    int arr[] = { 8,  58, 71, 18, 31, 32, 63, 92,
                  43, 3,  91, 93, 25, 80, 28 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    replace(arr, n);
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
