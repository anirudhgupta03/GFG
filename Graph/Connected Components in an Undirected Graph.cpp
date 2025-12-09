class Solution {
  public:
    void solve(int curr, vector<int> &vis, vector<int> al[], vector<int> &component){
        
        vis[curr] = 1;
        component.push_back(curr);
        
        for(auto &adjNode: al[curr]){
            if(!vis[adjNode]){
                solve(adjNode, vis, al, component);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> al[V];
        
        for(auto &edge: edges){
            al[edge[0]].push_back(edge[1]);
            al[edge[1]].push_back(edge[0]);
        }
        
        vector<vector<int>> res;
        
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                vector<int> component;
                solve(i, vis, al, component);
                res.push_back(component);
            }
        }
        
        return res;
    }
};
