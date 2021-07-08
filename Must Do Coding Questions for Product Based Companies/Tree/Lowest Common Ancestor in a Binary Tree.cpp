class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* findLCA(Node* root, int n1, int n2, bool &flag1, bool &flag2){
        
        if(root == NULL){
            return NULL;
        }
        
        if(root -> data == n1){
            flag1 = true;
        }
        if(root -> data == n2){
            flag2 = true;
        }
        
        Node* l = findLCA(root->left,n1,n2,flag1,flag2);
        Node* r = findLCA(root->right,n1,n2,flag1,flag2);
        
        if(root -> data == n1 || root -> data == n2){
            return root;
        }
        if(l && r){
            return root;
        }
        if(l) return l;
        if(r) return r;
        return NULL;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL){
           return NULL;
       }
       
       bool flag1 = false, flag2 = false;
       
       Node* res = findLCA(root,n1,n2,flag1,flag2);
       
       if(flag1 && flag2)
       return res;
       
       return NULL;
    }
};
