/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool isIdentical(Node* T, Node* S){
        
        if(T == NULL && S == NULL){
            return true;
        }
        if(T == NULL || S == NULL || T -> data != S -> data){
            return false;
        }
        return isIdentical(T -> left, S -> left) && isIdentical(T -> right, S -> right);
    }
    bool isSubTree(Node* T, Node* S) 
    {
        if(T == NULL){
            return false;
        }
        
        bool flag = isIdentical(T, S);
        if(flag) return true;
        
        return isSubTree(T -> left, S) || isSubTree(T -> right, S);
    }
};
