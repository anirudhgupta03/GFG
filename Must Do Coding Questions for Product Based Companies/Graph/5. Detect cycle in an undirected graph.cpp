//Using DFS
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
};

//Using BFS
class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    
	    for(int i = 0; i < V; i++){
	        
	        if(!vis[i]){
	            
	            queue<pair<int,int>> q;
	            q.push({i,-1});
	            vis[i] = 1;
	            
	            while(!q.empty()){
	                
	                int node = q.front().first, par = q.front().second;
	                q.pop();
	                
	                for(int j = 0; j < adj[node].size(); j++){
	                    int child = adj[node][j];
	                    if(vis[child] && child != par){
	                        return true;
	                    }
	                    else if(!vis[child]){
	                        vis[child] = 1;
	                        q.push({child,node});
	                    }
	                }
	            }
	        }
	    }
	    return false;
	}
};
