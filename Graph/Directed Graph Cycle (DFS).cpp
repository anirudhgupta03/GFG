class Solution {
  public:
    bool detectCycle(int node, vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;
        for(auto &child: adj[node]){
            if(vis[child] == 0){
                if(detectCycle(child, vis, adj)) return true;
            }
            else{
                return true;
            }
        }
        vis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> vis(V, 0);  
        for(int i = 0; i < V; i++){
            if(detectCycle(i, vis, adj)) return true;
        }
        return false;
    }
};
