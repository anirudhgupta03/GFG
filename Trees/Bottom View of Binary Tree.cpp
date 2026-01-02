/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> res;
        if(root == NULL) return res;
        
        map<int, int> mp;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Node* node = q.front().first;
                int vLevel = q.front().second;
                q.pop();
                
                mp[vLevel] = node -> data;
                
                if(node -> left) q.push({node -> left, vLevel - 1});
                if(node -> right) q.push({node -> right, vLevel + 1});
            }
        }

        for(auto &node: mp){
            res.push_back(node.second);
        }
        return res;
    }
};
