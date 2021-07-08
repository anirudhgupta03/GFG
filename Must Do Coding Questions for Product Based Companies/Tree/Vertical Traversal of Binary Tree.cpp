class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        queue<pair<Node*,int>> q;
        map<int,vector<int>> m;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            Node* curr = q.front().first;
            int d = q.front().second;
            q.pop();
            m[d].push_back(curr -> data);
            if(curr -> left) q.push({curr -> left,d-1});
            if(curr -> right) q.push({curr -> right,d+1});
        }
        
        vector<int> res;
        for(auto x: m){
            vector<int> temp = x.second;
            for(int i = 0; i < temp.size(); i++){
                res.push_back(temp[i]);
            }
        }
        return res;
    }
};
