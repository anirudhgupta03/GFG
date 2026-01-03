/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* t;
    void solve(Node* root, Node* par, unordered_map<Node*, Node*> &mpp, int target){
        if(root == NULL) return;
        mpp[root] = par;
        if(root -> data == target) t = root; 
        solve(root -> left, root, mpp, target);
        solve(root -> right, root, mpp, target);
    }
    int minTime(Node* root, int target) {
        // code here
        t = NULL;
        unordered_map<Node*, Node*> mpp;
        solve(root, NULL, mpp, target);
        
        queue<Node*> q;
        q.push(t);
        
        unordered_set<Node*> vis;
        int time = -1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Node* curr = q.front();
                q.pop();
                vis.insert(curr);
                if(mpp[curr] && vis.find(mpp[curr]) == vis.end()) q.push(mpp[curr]);
                if(curr -> left && vis.find(curr -> left) == vis.end()) q.push(curr -> left);
                if(curr -> right && vis.find(curr -> right) == vis.end()) q.push(curr -> right);
            }
            time++;
        }
        return time;
    }
};
