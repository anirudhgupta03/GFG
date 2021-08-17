//Ref: https://www.youtube.com/watch?v=6nJ_fUcCTNU
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
vector<int> solve(Node* root){
    
    if(root == NULL){
        return {1,0,INT_MAX,INT_MIN};
    }
    
    if(root -> left == NULL && root -> right == NULL){
        return {1,1,root->data,root->data};
    }
    
    vector<int> l = solve(root->left);
    vector<int> r = solve(root->right);
    
    if(l[0] && r[0]){
        if(root -> data > l[3] && root -> data < r[2]){
            int x = l[2];
            int y = r[3];
            if(x == INT_MAX) x = root -> data;
            if(y == INT_MIN) y = root -> data;
            return {1,l[1]+r[1]+1,x,y};
        }
    }
    return {0,max(l[1],r[1]),0,0};
}
int largestBst(Node *root)
{
	vector<int> ans = solve(root);
	return ans[1];
}

//Alter
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> solve(Node* root, int &ans){
        
        if(root == NULL){
            vector<int> v = {0,INT_MAX,INT_MIN};
            return v;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            vector<int> v = {1,root->data,root->data};
            return v;
        }
        
        vector<int> v1 = solve(root -> left, ans);
        vector<int> v2 = solve(root -> right, ans);
        
        int lmax = v1[1];
        int rmin = v2[2];
        
        vector<int> v(3);
        
        if(lmax < root -> data && root -> data < rmin){
            v[0] = v1[0] + v2[0] + 1;
            v[1] = rmin;
            v[2] = lmax;
        }
        else if(root -> right == NULL && lmax < root -> data){
            v[0] = v1[0] + 1;
            v[1] = root -> data;
            v[2] = v1[2];
        }
        else if(root -> left == NULL && rmin > root -> data){
            v[0] = v2[0] + 1;
            v[1] = v2[1];
            v[2] = root -> data;
        }
        else{
            v[0] = 0;
            v[1] = INT_MAX;
            v[2] = INT_MIN;
        }
        ans = max(ans, v[0]);
        return v;
    }
    int largestBst(Node *root)
    {
    	int ans = 1;
    	solve(root, ans);
    	return ans;
    }
};
