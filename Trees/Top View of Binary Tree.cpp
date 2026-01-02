class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> res;
        
        if(root == NULL){
            return res;
        }
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        map<int,int> mp;
        
        while(!q.empty()){
            
            Node* curr = q.front().first;
            int d = q.front().second;
            
            q.pop();
            
            if(mp.find(d) == mp.end()) mp[d] = curr -> data;
            
            if(curr -> left) q.push({curr -> left, d - 1});
            if(curr -> right) q.push({curr -> right, d + 1});
        }
        
        for(auto x: mp){
            res.push_back(x.second);
        }
        return res;
    }
};
