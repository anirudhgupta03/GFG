#define pii pair<int,int>
struct cmp{
    bool operator()(pii &p1, pii &p2){
        return p1.second > p2.second;
    }
};
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n + 1];
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
      
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push({1, 0});
        vector<int> dist(n + 1, INT_MAX);
        dist[1] = 0;
        vector<int> vis(n + 1, 0);
        vector<int> par(n + 1, -1);
        par[1] = 1;
        while(!pq.empty()){
            auto[curr, d] = pq.top();
            pq.pop();
            if(vis[curr]) continue;
            vis[curr] = 1;
            for(auto &child: adj[curr]){
                if(d + child.second < dist[child.first]){
                    dist[child.first] = d + child.second;
                    par[child.first] = curr;
                    pq.push({child.first, dist[child.first]});
                }
            }
        }
        if(dist[n] == INT_MAX) return {-1};
        vector<int> path;
        int i = n;
        while(i != 1){
            path.push_back(i);
            i = par[i];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        return path;
    }
};
