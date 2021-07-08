//Function to check whether a binary tree is balanced or not.
int check(Node* root,bool &flag){
    
    if(root == NULL){
        return 0;
    }
    
    int ldepth = check(root->left,flag);
    int rdepth = check(root->right,flag);
    
    if(abs(rdepth-ldepth) > 1){
        flag = false;
    }
    return max(ldepth,rdepth) + 1;
}   
bool isBalanced(Node *root)
{
    bool flag = true;
    check(root,flag);
    return flag;
}
