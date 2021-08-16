//https://www.codingninjas.com/codestudio/problems/median-of-a-bst_893184?leftPanelTab=0
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void solve(TreeNode<int> *root, int &count, int &e1, int &e2, int n){
    
    if(root == NULL){
        return;
    }
    
    solve(root -> left, count, e1, e2, n);
    count++;
    if(count == n/2 + 1){
        e1 = root -> data;
        return;
    }
    else if(count == n/2){
        e2 = root -> data;
    }
    solve(root -> right, count, e1, e2, n);
}
void findN(TreeNode<int> *root, int &n){
    
    if(root == NULL){
        return;
    }
    
    findN(root -> left, n);
    n++;
    findN(root -> right, n);
}
int medianBST(TreeNode<int>* root) 
{
    int n = 0;
    findN(root, n);
    
    int e1, e2, count = 0;
    solve(root, count, e1, e2, n);
    
    if(n % 2 == 0){
        return (e1 + e2)/2.0;
    }
    else{
        return e1;
    }
}
