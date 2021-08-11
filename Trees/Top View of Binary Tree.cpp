class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,vector<int>> mp;
        
        vector<int> res;
        
        if(root == NULL){
            return res;
        }
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            
            Node* curr = q.front().first;
            int d = q.front().second;
            q.pop();
            
            mp[d].push_back(curr -> data);
            if(curr -> left) q.push({curr -> left,d-1});
            if(curr -> right) q.push({curr -> right, d+1});
        }
        vector<int> temp;
        for(auto x: mp){
            temp = x.second;
            res.push_back(temp[0]);
        }
        return res;
    }

};

//Alter
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
