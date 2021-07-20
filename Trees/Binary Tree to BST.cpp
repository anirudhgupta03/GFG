//Ref: https://www.youtube.com/watch?v=8AnntMKIWlQ
/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void solve(Node* root, vector<int> &v){
        
        if(root == NULL){
            return;
        }
        
        solve(root -> left, v);
        v.push_back(root->data);
        solve(root->right,v);
    }
    void buildBST(Node* root, int &ind, vector<int> &v){
        
        if(root == NULL){
            return;
        }
        
        buildBST(root -> left,ind,v);
        root -> data = v[ind];
        ind++;
        buildBST(root -> right,ind,v);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> v;
        solve(root,v);
        sort(v.begin(),v.end());
        int ind = 0;
        buildBST(root,ind,v);
        return root;
    }
};
