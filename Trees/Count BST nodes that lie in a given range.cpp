//Function to count number of nodes in BST that lie in the given range.
void solve(Node* root, int l, int h, int &count){
    
    if(root == NULL){
        return;
    }
    
    if(root -> data >= l && root -> data <= h){
        count++;
    }
    
    if(root -> data >= h){
        solve(root -> left, l, h, count);
    }
    else if(root -> data <= l){
        solve(root -> right,l, h, count);
    }
    else if(root -> data > l && root -> data < h){
        solve(root -> left, l, h, count);
        solve(root -> right,l, h, count);
    }
}
int getCount(Node *root, int l, int h)
{
    int count = 0;
    solve(root, l, h, count);
    return count;
}
