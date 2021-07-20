#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
};
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}
node* buildTree(int l, int r, vector<int> &v){
  
  if(l > r){
    return NULL;
  }
  
  int mid = (l + r)/2;
  node* root = newNode(v[mid]);
  root->left = buildTree(l,mid-1,v);
  root->right = buildTree(mid+1,r,v);
  return root;
}
void inorder(node* root, vector<int> &v){
    
    if(root == NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
node* mergeTrees(node* root1, node* root2){
  
    vector<int> v1;
    inorder(root1,v1);
    vector<int> v2;
    inorder(root2,v2);
    
    vector<int> v3;
    int p1 = 0, p2 = 0;
  
    while(p1 < v1.size() && p2 < v2.size()){
      if(v1[p1] < v2[p2]){
        v3.push_back(v1[p1]);
        p1++;
      }
      else{
        v3.push_back(v2[p2]);
        p2++;  
      }
    }
  
    while(p1 < v1.size()){
      v3.push_back(v1[p1]);
      p1++;
    }
    while(p2 < v2.size()){
      v3.push_back(v2[p2]);
      p2++;
    }
    return buildTree(0,v3.size()-1,v3);
}
void printInorder(node* root){
  
  if(root == NULL){
    return;
  }
  printInorder(root->left);
  cout << root->data << endl;
  printInorder(root->right);
}
int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);
 
    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);
 
    node *mergedTree = mergeTrees(root1, root2);
 
    cout << "Following is Inorder traversal of the merged tree \n";
    printInorder(mergedTree);
 
    return 0;
}
