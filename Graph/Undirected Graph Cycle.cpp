// BFS Solution
class Solution {
  public:
    bool detectCycle(vector<int> adj[], vector<int>& vis, int start){
        queue<pair<int,int>> q;
        vis[start] = 1;
        q.push({start, -1});
        while(!q.empty()){
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto &child: adj[curr]){
                if(vis[child] == 0){
                    vis[child] = 1;
                    q.push({child, curr});
                }
                else if(child != par){
                    return true;
                }
            }    
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V, 0);
        queue<pair<int,int>> q;
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                if(detectCycle(adj, vis, i)){
                    return true;
                }
            }
        }
        return false;
    }
};

//DFS Solution
class Solution {
  public:
    bool detectCycle(int par, int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto &adjNode: adj[node]){
            if(adjNode != par && vis[adjNode] == 1){
                return true;
            }
            else if(!vis[adjNode]){
                if(detectCycle(node, adjNode, adj, vis)) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(detectCycle(-1, i, adj, vis)) return true;
            }
        }
        return false;
    }
};
