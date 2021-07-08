class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(x -> right != NULL){
            x = x -> right;
            while(x -> left){
                x =  x -> left;
            }
            return x;
        }
        else{
            Node* successor;
            
            while(root != x){
                if(root -> data < x -> data){
                    root = root -> right;
                }
                else if(root -> data > x -> data){
                    successor = root;
                    root = root -> left;
                }
            }
            return successor;
        }
    }
};
