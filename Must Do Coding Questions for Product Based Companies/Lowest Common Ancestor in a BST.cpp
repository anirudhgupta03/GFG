//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   while(1){
       if(root -> data < n1  && root -> data < n2){
           root = root -> right;
       }
       else if(root -> data > n1 && root -> data > n2){
           root = root -> left;
       }
       else{
           return root;
       }
   }
}
