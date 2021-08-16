//https://www.codingninjas.com/codestudio/problems/k-sum-path-in-a-binary-tree_893543?leftPanelTab=0
/*************************************************************
    
    Following is the Binary Tree node structure.
    
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
    
            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }
    };
    
*************************************************************/
#include<bits/stdc++.h>
using namespace std;
void solve(BinaryTreeNode<int> *root, int k, vector<int> &path, vector<vector<int>> &res){
    
    if(root == NULL){
        return;
    }
    
    path.push_back(root -> data);
    solve(root -> left, k, path, res);
    solve(root -> right, k, path, res);
    
    int f = 0;
    vector<int> temp;
    for(int j = path.size() - 1; j >= 0; j--){
        f += path[j];
        temp.push_back(path[j]);
        if(f == k){
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
            reverse(temp.begin(),temp.end());
        }
    }
    path.pop_back();
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    vector<int> path;
    vector<vector<int>> res;
    solve(root, k, path, res);
    return res;
}
