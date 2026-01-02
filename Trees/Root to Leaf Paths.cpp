/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root, vector<int> &path, vector<vector<int>> &allPaths){
        if(root == NULL){
            return;
        }
        path.push_back(root -> data);
        if(root -> left == NULL && root -> right == NULL){
            allPaths.push_back(path);
        }
        solve(root -> left, path, allPaths);
        solve(root -> right, path, allPaths);
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> allPaths;
        if(root == NULL) return allPaths;
        vector<int> path;
        solve(root, path, allPaths);
        return allPaths;
    }
};
