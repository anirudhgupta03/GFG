class Solution
{
    public:
    Node* solve(Node* root){
        
        if(root == NULL){
            return NULL;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            return root;
        }
        
        Node* ltail = solve(root -> left);
        Node* rtail = solve(root -> right);
        
        if(ltail && rtail){
            ltail -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
        }
        else if(ltail){
            root -> right = root -> left;
            root -> left = NULL;
            return ltail;
        }
        return rtail;
    }
    void flatten(Node *root)
    {
        root = solve(root);
    }
};
