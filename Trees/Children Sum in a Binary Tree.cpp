/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root == NULL) return true;
        
        if(root -> left == NULL && root -> right == NULL) return true;
        
        int lval = (root -> left) ? root -> left -> data : 0;
        int rval = (root -> right) ? root -> right -> data : 0;
        
        if(root -> data != lval + rval) return false;
        
        return isSumProperty(root -> left) && isSumProperty(root -> right);
    }
};
