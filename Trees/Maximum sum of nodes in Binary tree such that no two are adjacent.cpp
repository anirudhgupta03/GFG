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
