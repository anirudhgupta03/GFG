class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &res){
	    
	    vis[node] = 1;
	    res.push_back(node);
	    
	    for(int i = 0; i < adj[node].size(); i++){
	        int child = adj[node][i];
	        if(vis[child] == 0){
	            dfs(child,vis,adj,res);
	        }
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> vis(V,0);
	    vector<int> res;
	    
	    dfs(0,vis,adj,res);
	    
	    return res;
	}
};
