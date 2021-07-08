class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool check(Node* root, int &minval, int &maxval){
        
        if(root == NULL){
            return true;
        }
        
        if(root -> data > minval && root -> data < maxval){
            return check(root->left,minval,root->data) && check(root->right,root->data,maxval);
        }
        return false;
    }
    bool isBST(Node* root) 
    {
        int minval = INT_MIN, maxval = INT_MAX;
        
        return check(root,minval,maxval);
    }
};
