
/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST
void inorder(Node* root, vector<int> &v){
    
    if(root == NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
Node* buildTree(int l, int r, vector<int> &v){
    
    if(l > r){
        return NULL;
    }
    
    int mid = (l + r)/2;
    Node* root = new Node(v[mid]);
    root -> left = buildTree(l,mid-1,v);
    root -> right = buildTree(mid+1,r,v);
    return root;
}
Node* buildBalancedTree(Node* root)
{
    vector<int> v;
    inorder(root,v);
	return buildTree(0,v.size()-1,v);
}
