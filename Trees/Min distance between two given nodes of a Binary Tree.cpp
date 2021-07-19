/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
int findDis(Node* root, int n, int &d, int temp){
    
    if(root == NULL){
        return 0;
    }
    
    if(root -> data == n){
        d = temp;
    }
    
    findDis(root -> left, n, d, temp + 1);
    findDis(root -> right, n, d, temp + 1);
}
Node* findLCA(Node* root, int a, int b){
    
    if(root == NULL){
        return NULL;
    }
    
    if(root -> data == a || root -> data == b){
        return root;
    }
    
    Node* l = findLCA(root -> left, a, b);
    Node* r = findLCA(root -> right, a, b);
    
    if(l && r){
        return root;
    }
    if(l){
        return l;
    }
    return r;
}
int findDist(Node* root, int a, int b) {
    
    Node* temp = findLCA(root,a,b);
    
    int d1 = 0, t = 0;
    findDis(temp,a,d1,t);
    
    int d2 = 0;
    t = 0;
    findDis(temp,b,d2,t);
    
    return d1 + d2;
}   
