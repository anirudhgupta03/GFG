class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        
        vector<int> dist(V, 100000000);
        dist[S] = 0;
        
        for(int i = 0; i < V - 1; i++){
            for(int j = 0; j < adj.size(); j++){
                int u = adj[j][0], v = adj[j][1], w = adj[j][2];
                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        return dist;
    }
};
