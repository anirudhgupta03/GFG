class Solution{
public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    #define pii pair<int,int>
    
    void dijkstras(int S, int V,vector<int> &dist, vector<pair<int,int>> al[]){
        
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        
        pq.push({0,S});
        
        vector<int> vis(V,0);
        
        while(!pq.empty()){
            
            
            int curr = pq.top().second, curr_d = pq.top().first;
            
            pq.pop();
            
            if(vis[curr]) continue;
            vis[curr] = 1;
            
            for(int i = 0; i < al[curr].size(); i++){
                
                int child = al[curr][i].first, w = al[curr][i].second;
                
                if(curr_d + w < dist[child]){
                    
                    dist[child] = curr_d + w;
                    pq.push({dist[child],child});
                }
            }
        }
    }
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        
        vector<int> dist(V,INT_MAX);
        
        dist[S] = 0;
        
        vector<pair<int,int>> al[V];
        
        for(int i = 0; i < V; i++){
            
            for(int j = 0; j < adj[i].size(); j++){
                
                int a = i, b = adj[i][j][0], w = adj[i][j][1];
                al[a].push_back({b,w});
                al[b].push_back({a,w});
            }
        }
        
        dijkstras(S,V,dist,al);
        
        vector<int> res;
        for(int i = 0; i < V; i++){
            res.push_back(dist[i]);
        }
        
        return res;
    }
};
