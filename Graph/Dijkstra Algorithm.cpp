// User Function Template
#define pii pair<int,int>
struct cmp{
  bool operator()(pii &p1, pii &p2){
      return p1.second > p2.second;
  }  
};
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> al[V];
        
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            al[u].push_back({v, w});
            al[v].push_back({u, w});
        }
        
        vector<int> dist(V, INT_MAX);
        vector<int> vis(V, 0);
        priority_queue<pii, vector<pii>, cmp> pq;
        
        dist[src] = 0;
        pq.push({src, 0});
        
        while(!pq.empty()){
            int curr = pq.top().first;
            int wt = pq.top().second;
            pq.pop();
            
            if(vis[curr]) continue;
            vis[curr] = 1;
            
            for(auto &adjNode: al[curr]){
                if(wt + adjNode.second < dist[adjNode.first]){
                    dist[adjNode.first] = wt + adjNode.second;
                    pq.push({adjNode.first, dist[adjNode.first]});
                } 
            }
        }
        
        return dist;
    }
};
