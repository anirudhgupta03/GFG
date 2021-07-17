class Solution {
  public:
    vector <int> bottomView(Node *root) {
        
        map<int,vector<int>> mp;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
               Node* curr = q.front().first;
               int lev = q.front().second;
               q.pop();
               
               mp[lev].push_back(curr -> data);
               
               if(curr -> left) q.push({curr -> left, lev - 1});
               if(curr -> right) q.push({curr -> right, lev + 1});
            }
        }
        
        vector<int> res;
        for(auto x: mp){
            vector<int> temp = x.second;
            res.push_back(temp[temp.size()-1]);
        }
        return res;
    }
};
