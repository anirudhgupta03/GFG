class Solution{
public:
    bool dfs(int node, vector<int> &color, vector<int> adj[]){
        
        for(int i = 0; i < adj[node].size(); i++){
            
            int child = adj[node][i];
            
            if(color[child] == -1){
                color[child] = 1 - color[node];
                if(!dfs(child,color,adj)){
                    return false;
                }
            }
            else if(color[child] == color[node]){
                return false;
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> color(V,-1);
	    
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1 && !dfs(i,color,adj)){
	            return false;
	        }
      }
	    return true;
	}

};
