/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        stack<Node*> s;
        vector<int> res;
        
        while(root){
            s.push(root);
            root = root -> left;
        }
        
        while(!s.empty()){
            
            Node* curr = s.top();
            s.pop();
            res.push_back(curr -> data);
            
            curr = curr -> right;
            while(curr){
                s.push(curr);
                curr = curr -> left;
            }
        }
        return res;
    }
};
