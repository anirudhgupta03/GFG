// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& adj, int S) {
        // Code here
        vector<int> dist(V, 100000000);
        
        dist[S] = 0;
        
        for(int i = 0; i < V - 1; i++){
            for(int j = 0; j < adj.size(); j++){
                int u = adj[j][0], v = adj[j][1], w = adj[j][2];
                if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        bool flag = false;
        for(int j = 0; j < adj.size(); j++){
            int u = adj[j][0], v = adj[j][1], w = adj[j][2];
            if(dist[u] != 100000000 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                flag = true;
            }
        }
        if(flag) return {-1};
        return dist;
    }
};
