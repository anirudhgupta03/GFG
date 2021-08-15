//Ref: https://www.youtube.com/watch?v=BH_btihSwVM
#include <bits/stdc++.h>
using namespace std;
 
// custom data type for tree building
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
 
// Below function accepts sttring and a pointer variable as
// an argument
// and draw the tree. Returns the root of the tree
Node* constructtree(string s, int &start)
{
    // Assuming there is/are no negative
    // character/characters in the string
    if(s.size() == 0 || start >= s.size())
        return NULL;
  
    bool neg = false;
    if(s[start] == '-'){
      neg = true;
      start++;
    }
 
    // constructing a number from the continuous digits
    int num = 0;
    while(start < s.size() && isdigit(s[start])){
       num = 10*num + s[start] - '0';
       start++;
    }
  
    // creating a node from the constructed number from
    // above 
    if(neg) num = -num;
    struct Node* root = new Node(num);
 
    // check if start has reached the end of the string
    if(start >= s.size())
        return root;
 
    // As soon as we see first right parenthesis from the
    // current node we start to construct the tree in the
    // left
    if(start < s.size() && s[start] == '(') {
        start++;
        root->left = constructtree(s, start);
    }
    if(start < s.size() && s[start] == ')'){
        start++;
    } 
 
    // As soon as we see second right parenthesis from the
    // current node we start to construct the tree in the
    // right
    if(start < s.size() && s[start] == '('){
        start++;
        root->right = constructtree(s, start);
    }
    if(start < s.size() && s[start] == ')'){
        start++;
    }
    return root;
}
void preorder(Node* root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    string s = "4(2(3)(1))(6(5))";
    // cin>>s;
    int start = 0;
    Node* root = constructtree(s, start);
    preorder(root);
    return 0;
}

//https://www.codingninjas.com/codestudio/problems/binary-tree-from-bracket_1118117?leftPanelTab=1
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

#include<bits/stdc++.h>
using namespace std;
*************************************************************/
BinaryTreeNode<int>* solve(int &ind, string &str){
    
    if(str.size() == 0 || ind >= str.size()){
        return NULL;
    }
    
    bool neg = false;
    if(str[ind] == '-'){
        neg = true;
    }
    
    int num = 0;
    while(ind < str.size() && isdigit(str[ind])){
        num = 10*num + str[ind] - '0';
        ind++;
    }
    
    if(neg) num = -num;
    
    if(num == 0){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(num);
    
    if(ind >= str.size()){
        return root;
    }
    
    if(ind < str.size() && str[ind] == '('){
        ind++;
        root -> left = solve(ind, str);
    }
    if(ind < str.size() && str[ind] == ')'){
        ind++;
    }
    
    if(ind < str.size() && str[ind] == '('){
        ind++;
        root -> right = solve(ind, str);
    }
    if(ind < str.size() && str[ind] == ')'){
        ind++;
    }
    return root;
}
BinaryTreeNode<int>* treeFromBracket(string &str)
{	
    int ind = 0;
    return solve(ind, str);
}
