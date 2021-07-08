// return true/false denoting whether the tree is Symmetric or not
bool check(Node* root1, Node* root2){
    
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL || root1 -> data != root2 -> data){
        return false;
    }
    
    if(root1 -> data == root2 -> data){
        return check(root1->left, root2->right) && check(root1->right,root2->left);
    }
}
bool isSymmetric(struct Node* root)
{
	return check(root,root);
}
