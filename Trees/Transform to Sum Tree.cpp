/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node* node){
        
        if(node == NULL){
            return 0;
        }
        
        int l = solve(node -> left);
        int r = solve(node -> right);
        
        int temp = node -> data;
        node -> data = l + r;
        return temp + node -> data;
    }
    void toSumTree(Node *node)
    {
        solve(node);
    }
};
