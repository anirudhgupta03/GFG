class Solution
{
    public:
    int check(Node* root, bool &flag){
        
        if(root == NULL){
            return 0;
        }
        
        if(root -> left == NULL &&  root -> right == NULL){
            return root -> data;
        }
        int l = check(root->left,flag);
        int r = check(root->right,flag);
        
        if(root -> data != l + r){
            flag = false;
        }
        
        return root -> data + l + r;
    }
    bool isSumTree(Node* root)
    {
         bool flag = true;
         check(root,flag);
         return flag;
    }
};
