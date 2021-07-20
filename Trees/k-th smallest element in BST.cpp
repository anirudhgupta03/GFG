struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Return the Kth smallest element in the given BST 
    void solve(Node* root, int &K, int &ans){
        
        if(root == NULL){
            return;
        }
        
        solve(root -> left, K, ans);
        
        K--;
        if(K == 0){
            ans = root -> data;
            return;
        }
        solve(root -> right, K, ans);
    }
    int KthSmallestElement(Node *root, int K)
    {
        int ans = -1;
        solve(root,K,ans);
        return ans;
    }
};
