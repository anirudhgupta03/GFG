#define pii pair<int,int>
struct cmp{
  bool operator()(pii &p1, pii &p2)  {
      return p1.second > p2.second;
  }
};
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        
        for(auto &edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        vector<int> vis(V, 0);
        
        set<pii> st;
        st.insert({0, src});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int d= it.first, curr = it.second;
            st.erase(it);
            
            for(auto &child: adj[curr]){
                if(d + child.second < dist[child.first]){
                    if(dist[child.first] != INT_MAX){
                        st.erase({dist[child.first], child.first});
                    }
                    dist[child.first] = d + child.second;
                    st.insert({dist[child.first], child.first});
                }
            }
        }
        return dist;
    }
};
