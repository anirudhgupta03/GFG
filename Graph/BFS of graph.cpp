class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    queue<int> q;
	    q.push(0);
	    
	    vector<int> vis(V,0);
	    vis[0] = 1;
	    
	    vector<int> res;
	    
	    while(!q.empty()){
	        
	        int curr = q.front();
	        res.push_back(curr);
	        q.pop();
	        
	        for(int i = 0; i < adj[curr].size(); i++){
	            int child = adj[curr][i];
	            if(vis[child] == 0){
	                q.push(child);
	                vis[child] = 1;
	            }
	        }
	    }
	    
	    return res;
	}
};
