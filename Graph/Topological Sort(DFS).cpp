class Solution {
  public:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]){
        vis[node] = 1;
        for(auto &child: adj[node]){
            if(!vis[child]) dfs(child, vis, st, adj);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
