class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(int node, vector<int> &vis, vector<int> adj[]){
	    
	    vis[node] = 1;
	    
	    for(int i = 0; i < adj[node].size(); i++){
	        int child = adj[node][i];
	        
	        if(vis[child] == 0){
	            
	            if(dfs(child,vis,adj)){
	                return true;
	            }
	        }
	        else if(vis[child] == 1){
	            return true;
	        }
	    }
	    
	    vis[node] = 2;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    
	    for(int i = 0; i < V; i++){
	        
	        if(vis[i] == 0 && dfs(i,vis,adj)){
	            return true;
	        }
	    }
	    
	    return false;
	}
};
