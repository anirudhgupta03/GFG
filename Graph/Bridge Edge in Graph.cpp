//Method - 1
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node, vector<int> &vis, vector<int> adj[]){
        
        vis[node] = 1;
        
        for(int i = 0; i < adj[node].size(); i++){
            int child = adj[node][i];
            if(vis[child] == 0){
                dfs(child,vis,adj);
            }
        }
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> vis(V,0);
        
        int cc_count1 = 0;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cc_count1++;
            }
        }
        
        vector<int> v = adj[c];
        for(int i = 0; i < v.size(); i++){
            if(v[i] == d){
                v.erase(v.begin()+i);
                break;
            }
        }
        adj[c] = v;
        v = adj[d];
        for(int i = 0; i < v.size(); i++){
            if(v[i] == c){
                v.erase(v.begin()+i);
                break;
            }
        }
        adj[d] = v;
        
        for(int i = 0; i < V; i++){
            vis[i] = 0;
        }
        
        int cc_count2 = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                cc_count2++;
            }
        }
        
        if(cc_count2 > cc_count1){
            return true;
        }
        return false;
    }
};

//Method - 2
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void solve(int node, int par, vector<int> &low, vector<int> &in, int &timer, int c, int d, vector<int> &vis, vector<int> adj[], bool &flag){
        
        vis[node] = 1;
        low[node] = in[node] = timer++;
        
        for(int i = 0; i < adj[node].size(); i++){
            
            int child = adj[node][i];
            
            if(child == par){
                continue;
            }
            if(vis[child]){
                low[node] = min(low[node], in[child]);
            }
            else{
                solve(child,node,low,in,timer,c,d,vis,adj,flag);
                
                if(low[child] > in[node]){
                    
                    if(node == c && child == d || node == d && child == c){
                        flag = true;
                    }
                }
                
                low[node] = min(low[node], low[child]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> low(V), in(V);
        int timer = 0;
        
        vector<int> vis(V,0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                bool flag = false;
                solve(i,-1,low,in,timer,c,d,vis,adj,flag);
                if(flag){
                    return true;
                }
            }
        }
        
        return false;
    }
};
