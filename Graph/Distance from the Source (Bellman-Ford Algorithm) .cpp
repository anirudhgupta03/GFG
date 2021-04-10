
class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    void bellmanford(int S, int V, vector<int> &dist, vector<vector<int>> &adj){
        
        bool flag;
        for(int i = 0; i < V - 1; i++){
            
            flag = false;
            for(int j = 0; j < adj.size(); j++){
                
                int u = adj[j][0], v = adj[j][1], w = adj[j][2];
                
                if(dist[u] != INT_MAX){
                    
                    if(dist[u] + w < dist[v]){
                        dist[v] = dist[u] + w;
                        flag = true;
                    }
                }
            }
            if(flag == false) break;
        }
    }
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        
        vector<int> dist(V,INT_MAX);
        
        dist[S] = 0;
        
        
        bellmanford(S,V,dist,adj);
        
        vector<int> res;
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX){
                res.push_back(100000000);
                continue;
            }
            res.push_back(dist[i]);
        }
        
        return res;
    }
};
