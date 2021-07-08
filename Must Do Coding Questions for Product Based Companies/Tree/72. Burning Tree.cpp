class Solution {
    public:
    void find(Node* root, Node* &start, int target){
        
        if(root == NULL){
            return;
        }
        if(root -> data == target){
            start = root;
            return;
        }
        find(root->left,start,target);
        find(root->right,start,target);
    }
    int minTime(Node* root, int target) 
    {
        Node* start;
        
        find(root,start,target);
        
        unordered_map<Node*,Node*> par;
        
        queue<Node*> q1;
        q1.push(root);
        
        while(!q1.empty()){
            
            Node* curr = q1.front();
            q1.pop();
            
            if(curr -> left){
                q1.push(curr->left);
                par[curr->left] = curr;
            }
            if(curr -> right){
                q1.push(curr->right);
                par[curr->right] = curr;
            }
        }
        
        unordered_map<Node*,int> vis;
        vis[start] = 1;
        
        queue<pair<Node*,int>> q2;
        q2.push({start,0});
        
        int burnTime = 0;
        
        while(!q2.empty()){
            
            Node* curr = q2.front().first;
            int lev = q2.front().second;
            q2.pop();
            burnTime = max(burnTime,lev);
            
            if(curr -> left && vis[curr->left] == 0){
                q2.push({curr->left,lev+1});
                vis[curr->left] = 1;
            }
            if(curr->right && vis[curr->right] == 0){
                q2.push({curr->right,lev+1});
                vis[curr->right] = 1;
            }
            if(par[curr] != NULL && vis[par[curr]] == 0){
                q2.push({par[curr],lev+1});
                vis[par[curr]] = 1;
            }
        }
        
        return burnTime;
    }
};
