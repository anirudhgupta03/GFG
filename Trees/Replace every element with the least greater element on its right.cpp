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

//Least Greater Element
//https://www.codingninjas.com/codestudio/problems/least-greater-element_1164266?leftPanelTab=0
//Method - 1
struct Node{
  
   int data;
   Node* left, *right;
    
   Node(int val){
       data = val;
       left = NULL;
       right = NULL;
   } 
};
void insert(Node* root, int val){
    
    while(1){
        if(root -> data > val){
            if(root -> left){
                root = root -> left;
            }
            else{
                root -> left = new Node(val);
                break;
            }
        }
        else if(root -> data < val){
            if(root -> right){
                root = root -> right;
            }
            else{
                root -> right = new Node(val);
                break;
            }
        }
        else{
            break;
        }
    }
}
void search(Node* root, int value, int &val){
    
    while(root){
        
        if(root -> data > value){
            val = root -> data;
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
}
vector<int> leastGreaterElement(vector<int> &arr) 
{	
    int n = arr.size();
	   Node* root = new Node(arr[n - 1]);
    
    vector<int> res(n);
    res[n-1] = -1;
    
    for(int i = n - 2; i >= 0; i--){
        int val = -1;
        search(root, arr[i], val);
        insert(root, arr[i]);
        res[i] = val;
    }
    return res;
}

//Method - 2
struct Node{
  
   int data;
   Node* left, *right;
    
   Node(int val){
       data = val;
       left = NULL;
       right = NULL;
   } 
};
void insertInBST(Node* node, int data, int &val)
{
   while(1){
      if(node -> data > data){
        val = node -> data;
        if(node -> left) node = node -> left;
        else{
          node -> left = new Node(data);
          break;
        }
      }
      else{
        if(node -> right) node = node -> right;
        else{
          node -> right = new Node(data);
          break;
        }
      }
   }
}
vector<int> leastGreaterElement(vector<int> &arr) 
{	
    int n = arr.size();
	Node* root = new Node(arr[n - 1]);
    
    vector<int> res(n);
    res[n-1] = -1;
    
    for(int i = n - 2; i >= 0; i--){
        int val = -1;
        insertInBST(root, arr[i],val);
        res[i] = val;
    }
    return res;
}
