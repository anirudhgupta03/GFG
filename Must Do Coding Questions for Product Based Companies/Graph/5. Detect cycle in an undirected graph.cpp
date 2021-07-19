class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(int node, int par, vector<int> adj[], vector<int> &vis){
        
        vis[node] = 1;
        
        for(int i = 0; i < adj[node].size(); i++){
            
            int child = adj[node][i];
            
            if(vis[child] == 0){
                if(dfs(child,node,adj,vis)){
                    return true;
                }
            }
            else{
                if(child != par){
                    return true;
                }
            }
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    
	    for(int i = 0; i < V; i++){
	        if(vis[i] == 0 && dfs(i,-1,adj,vis)){
	            return true;
	        }
	    }
	    return false;
	}
