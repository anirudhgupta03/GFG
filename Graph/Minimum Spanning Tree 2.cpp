class Solution{
    
int selectMinVertex(vector<int> &wt, vector<int> &vis){
    int minimum = INT_MAX;
    int vertex;

    for(int i = 0; i < wt.size(); i++){

        if(vis[i] == 0 && wt[i] < minimum){
            vertex = i;
            minimum = wt[i];
        }
    }
    return vertex;
}
	public:
	// Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    void prims(vector<int> &wt, vector<int> &vis, vector<vector<int>> adj[], int V){
        
        int src = 0;
        
        for(int i = 0; i <= V -2; i++){
            
            int src = selectMinVertex(wt, vis);
            vis[src] = 1;
            
            for(int j = 0; j < adj[src].size(); j++){
                
                if(vis[adj[src][j][0]] == 0 && adj[src][j][1] < wt[adj[src][j][0]]){
                    
                    wt[adj[src][j][0]] = adj[src][j][1];
                }
            }
            
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<int> wt(V,INT_MAX);
        vector<int> vis(V,0);
        
        wt[0] = 0;
        
        int ans = 0;
        
        prims(wt, vis, adj, V);
        
        for(int i = 0; i < V; i++){
            ans += wt[i];
        }
        return ans;
    }
};
