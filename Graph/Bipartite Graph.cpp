//Using BFS
class Solution{
public:
    bool bfs(int node, int clr, vector<int> &vis, vector<int> &color, vector<int> adj[]){
        
        vis[node] = 1;
        color[node] = clr;
        
        queue<int> q;
        q.push(node);
        
        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            
            for(int i = 0; i < adj[curr].size(); i++){
                
                int child = adj[curr][i];
                
                if(vis[child] == 0){
                    color[child] = 1 - color[curr];
                    vis[child] = 1;
                    q.push(child);
                }
                else if(color[curr] == color[child]){
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> vis(V,0);
	    vector<int> color(V);
	    
	    bool flag = true;
	    
	    for(int i = 0; i < V; i++){
	        
	        if(vis[i] == 0){
    	        if(!bfs(i,1,vis,color,adj)){
    	            flag = false;
    	        }
	        }
	    }
	    return flag;
	}

};
