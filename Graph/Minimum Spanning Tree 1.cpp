//MST Implementation using Prims Algo using Priority Queue
class Solution{
    #define pii pair<int,int>

	public:
	// Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    void prims(vector<int> &wt, vector<int> &vis, vector<vector<int>> adj[], int V){
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        int src = 0;
        
        pq.push({0,src});
        
        wt[src] = 0;
        
        while(!pq.empty()){
            
            int u = pq.top().second;
            pq.pop();
            vis[u] = 1;
            
            for(int j = 0; j < adj[u].size(); j++){
                
                int v = adj[u][j][0], w = adj[u][j][1];
                
                if(vis[v] == 0 && w < wt[v]){
                    
                    wt[v] = w;
                    pq.push({wt[v],v});
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
