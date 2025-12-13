class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        
        for(auto &edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        vector<int> vis(V, 0);
        vector<int> dist(V, INT_MAX);
        int mstWt = 0;
        
        while(!pq.empty()){
            auto[wt, node] = pq.top();
            pq.pop();
            
            if(vis[node]) continue;
            vis[node] = 1;
            mstWt += wt;
            
            for(auto &[nbr, w]: adj[node]){
                if(w <= dist[nbr]){
                    dist[nbr] = w;
                    pq.push({w, nbr});
                }
            }
        }
        return mstWt;
    }
};
