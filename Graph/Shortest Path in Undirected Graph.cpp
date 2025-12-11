class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> adj[V];
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(src);

        vector<int> dist(V, -1);
        dist[src] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &child: adj[curr]){
                if(dist[child] == -1){
                    dist[child] = dist[curr] + 1;
                    q.push(child);
                }
            }
        }
        return dist;
    }
};
