//Similar Question: 337. House Robber III
#include<iostream>
#include<vector>
using namespace std;
 
class Node
{
public:
    int data;
    Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 
vector<int> maxSumHelper(Node *root)
{
    if (root==NULL)
    {
        vector<int> temp = {0,0};
        return temp;
    }
    vector<int> v1 = maxSumHelper(root->left);
    vector<int> v2 = maxSumHelper(root->right);
    
    vector<int> res(2);
    res[0] = v1[1] + root -> data + v2[1];
    res[1] = max(v1[0],v1[1]) + max(v2[0],v2[1]);
    return res;
}
 
int maxSum(Node *root)
{
    vector<int> res = maxSumHelper(root);
    return max(res[0],res[1]);
}

int main()
{
    Node *root= new Node(10);
    root->left= new Node(1);
    root->left->left= new Node(2);
    root->left->left->left= new Node(1);
    root->left->right= new Node(3);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(5);
    cout << maxSum(root);
    return 0;
}

//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-nodes-in-a-binary-tree-such-that-no-two-nodes-are-adjacent_1118112?leftPanelTab=1
//Maximum Sum Of Nodes
//Top-Down Approach
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;

vector<int> solve(TreeNode<int> *root, map<TreeNode<int>*, vector<int>> &mp){
    
    if(root == NULL){
        vector<int> temp(2,0);
        return temp;
    }
    
    if(root -> left == NULL && root -> right == NULL){
        vector<int> temp(2);
        temp[0] = root -> data;
        temp[1] = 0;
        return temp;
    }
    
    if(mp.find(root) != mp.end()){
        return mp[root];
    }
    vector<int> l = solve(root -> left, mp);
    vector<int> r = solve(root -> right, mp);
    
    vector<int> temp(2);
    temp[0] = root -> data + l[1] + r[1];
    temp[1] = max(l[0],l[1]) + max(r[0],r[1]);
    
    return mp[root] = temp;
}
int maximumSumOfNodes(TreeNode<int> *root)
{
    map<TreeNode<int>*, vector<int>> mp;
	vector<int> v = solve(root, mp);
    return max(v[0],v[1]);
}
