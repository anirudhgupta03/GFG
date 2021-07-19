/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void solve(Node* root, int &maxLen, int &maxSum, int currLen, int currSum){
        
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            if(maxLen < currLen + 1){
                maxLen = currLen + 1;
                maxSum = currSum + root -> data;
            }
            else if(maxLen == currLen + 1){
                maxSum = max(maxSum, currSum + root -> data);
            }
            return;
        }
        
        solve(root -> left, maxLen, maxSum, currLen + 1, currSum + root -> data);
        solve(root -> right, maxLen, maxSum, currLen + 1, currSum + root -> data);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxLen = 0, maxSum = 0, currLen = 0, currSum = 0;
        
        solve(root,maxLen,maxSum,currLen,currSum);
        
        return maxSum;
    }
};
