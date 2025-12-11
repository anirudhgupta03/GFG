// User function Template for C++
#define pii pair<int,int>
struct cmp{
    bool operator()(pii &p1, pii &p2){
        return p1.second > p2.second;
    }
};
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> al[V];
        
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            al[u].push_back({v, w});
        }
        
        vector<int> dist(V, INT_MAX);
        priority_queue<pii, vector<pii>, cmp> pq;
      
        dist[0] = 0;
        pq.push({0, 0});
        
        vector<int> vis(V, 0);
        
        while(!pq.empty()){
            int curr = pq.top().first;
            int wt = pq.top().second;
            pq.pop();
            
            if(vis[curr]) continue;
            vis[curr] = 1;
            
            for(auto &adj: al[curr]){
                int adjNode = adj.first, edgeWt = adj.second;
                if(wt + edgeWt < dist[adjNode]){
                    dist[adjNode] = wt + edgeWt;
                    pq.push({adjNode, wt + edgeWt});
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};
