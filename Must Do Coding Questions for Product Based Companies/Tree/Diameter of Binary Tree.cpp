class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node* root, int &res){
        
        if(root == NULL){
            return 0;
        }
        
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        int temp = max(l,r) + 1;
        int ans = max(temp,1+l+r);
        res = max(res,ans);
        
        return temp;
    }
    int diameter(Node* root) {
        
        int res;
        solve(root,res);
        return res;
    }
};
