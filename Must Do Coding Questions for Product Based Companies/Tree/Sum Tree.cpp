class Solution
{
    public:
    int check(Node* root,bool &flag){
        
        if(root == NULL){
            return 0;
        }
        
        int lsum = check(root->left,flag);
        int rsum = check(root->right,flag);
        
        if(!(lsum == 0 && rsum == 0)){
            if(lsum + rsum != root -> data){
                flag = false;
            }
        }
        return lsum + rsum + root -> data;
    }
    bool isSumTree(Node* root)
    {
         bool flag = true;
         check(root,flag);
         return flag;
    }
};
