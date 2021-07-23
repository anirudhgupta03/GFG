//Ref: https://www.youtube.com/watch?v=O0qFZUpVxm0&t=605s
/*
struct Node
{
    int data;
    int lis;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        lis = 0;
        left = right = NULL;
    }
};
*/


int LISS(Node *root)
{
    if (root == NULL)
    return 0;
 
    // Calculate size excluding the current node
    int size_excl = LISS(root->left) +
                    LISS(root->right);
 
    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
        size_incl += LISS(root->left->left) +
                     LISS(root->left->right);
    if (root->right)
        size_incl += LISS(root->right->left) +
                     LISS(root->right->right);
 
    // Return the maximum of two sizes
    return max(size_incl, size_excl);
}
