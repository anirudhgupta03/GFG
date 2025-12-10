class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> adj[V];
        vector<int> indegree(V, 0);
        for(auto &edge: edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            count++;
            for(auto &child: adj[curr]){
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }
        return count != V;
    }
};
