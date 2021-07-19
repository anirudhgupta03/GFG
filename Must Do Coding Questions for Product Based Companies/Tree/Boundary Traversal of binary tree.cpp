//Ref: https://www.youtube.com/watch?v=bzF9Ia1XISQ
//Method - 1
class Solution {
public:
    void LeftTree(Node* root, vector<int> &ans){
        
        if(root == NULL){
            return;
        }
        
        if(root -> left){
            ans.push_back(root -> data);
            LeftTree(root->left,ans);
        }
        else if(root -> right){
            ans.push_back(root -> data);
            LeftTree(root->right,ans);
        }
    }
    void Leaf(Node* root, vector<int> &ans){
        
        if(root == NULL){
            return;
        }
        Leaf(root->left,ans);
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(root -> data);
        }
        Leaf(root->right,ans);
    }
    void RightTree(Node* root, vector<int> &ans){
        
        if(root == NULL){
            return;
        }
        if(root -> right){
            RightTree(root->right,ans);
            ans.push_back(root->data);
        }
        else if(root -> left){
            RightTree(root->left,ans);
            ans.push_back(root->data);
        }
    }
    vector <int> printBoundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root -> data);
        LeftTree(root->left,ans);
        Leaf(root,ans);
        RightTree(root->right,ans);
        return ans;
    }
};

//Method - 2
/*struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void leftNodes(Node* root, vector<int> &res){
        
        bool flag = false;
        
        while(root){
            res.push_back(root -> data);
            flag = true;
            if(root -> left)
            root = root -> left;
            else
            root = root -> right;
        }
        if(flag) res.pop_back();
    }
    void rightNodes(Node* root, vector<int>&res){
        
        vector<int> temp;
        while(root){
            temp.push_back(root -> data);
            
            if(root -> right)
            root = root -> right;
            else
            root = root -> left;
        }
        
        for(int i = temp.size() - 2; i >= 0; i--){
            res.push_back(temp[i]);
        }
    }
    void leafNodes(Node* root, vector<int> &res){
        
        if(root == NULL){
            return;
        }
        if(root -> left == NULL && root -> right == NULL){
            res.push_back(root -> data);
            return;
        }
        leafNodes(root -> left,res);
        leafNodes(root -> right,res);
    }
    vector <int> printBoundary(Node *root)
    {
        vector<int> res;
        res.push_back(root -> data);
        leftNodes(root -> left,res);
        leafNodes(root,res);
        rightNodes(root -> right,res);
        return res;
    }
};
