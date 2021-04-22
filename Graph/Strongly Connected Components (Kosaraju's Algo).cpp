class Solution{
public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    void dfs1(int node, vector<int> &vis, vector<int> adj[], stack<int> &s){
        
        vis[node] = 1;
        
        for(int i = 0; i < adj[node].size(); i++){
            
            int child = adj[node][i];
            if(vis[child] == 0){
                dfs1(child, vis, adj, s);
            }
        }
        s.push(node);
    }
    void reverse(int V, vector<int> adj[], vector<int> rev[]){
        
        for(int i = 0; i < V; i++){
            
            for(int j = 0; j < adj[i].size(); j++){
                int child = adj[i][j];
                rev[child].push_back(i);
            }
        }
    }
    void dfs2(int node, vector<int> &vis, vector<int> rev[]){
        
        vis[node] = 1;
        
        for(int i = 0; i < rev[node].size(); i++){
            
            int child = rev[node][i];
            if(vis[child] == 0){
                dfs2(child, vis, rev);
            }
        }
    }
    int kosaraju(int V, vector<int> adj[]) {
        
        stack<int> s;
        
        vector<int> vis(V,0);
        
        for(int i = 0; i < V; i++){
            
            if(!vis[i]){
                dfs1(i,vis,adj,s);
            }
        }
        
        for(int i = 0; i < V; i++){
            vis[i] = 0;
        }
        
        vector<int> rev[V];
        
        reverse(V,adj,rev);
        
        int count = 0;
        
        while(!s.empty()){
            
            int curr = s.top();
            s.pop();
            
            if(!vis[curr]){
                count++;
                dfs2(curr,vis,rev);
            }
        }
        
        return count;
    }
};
