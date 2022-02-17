//Similar Question: https://leetcode.com/problems/binary-tree-cameras/
class Solution{
public:
    int cnt;
    int dfs(Node* root){
        if(root == NULL){
            return 1;
        }
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        
        if(l == 0 || r == 0){
            cnt++;
            return 2;
        }
        else if(l == 2 || r == 2){
            return 1;
        }
        else{
            return 0;
        }
    }
    int supplyVaccine(Node* root){
        cnt = 0;
        int ans = dfs(root);
        return ans == 0 ? cnt + 1 : cnt;
    }
};
