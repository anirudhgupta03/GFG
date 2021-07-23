//Using DFS
class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(int node, vector<int> &vis, vector<int> adj[]){
	    
	    vis[node] = 1;
	    
	    for(int i = 0; i < adj[node].size(); i++){
	        int child = adj[node][i];
	        
	        if(vis[child] == 0){
	            
	            if(dfs(child,vis,adj)){
	                return true;
	            }
	        }
	        else if(vis[child] == 1){
	            return true;
	        }
	    }
	    
	    vis[node] = 2;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<int> vis(V,0);
	    
	    for(int i = 0; i < V; i++){
	        
	        if(vis[i] == 0 && dfs(i,vis,adj)){
	            return true;
	        }
	    }
	    
	    return false;
	}
};

//Using BFS(Topological  Sort works only in Directed Acyclic Graph)
//Ref: https://www.youtube.com/watch?v=V6GxfKDyLBM
class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<int> in(V,0);
	   	
	   	for(int i = 0; i < V; i++){
	   	    vector<int> v = adj[i];
	   	    for(int j = 0; j < v.size(); j++){
	   	        in[v[j]]++;
	   	    }
	   	}
	   	
	   	queue<int> q;
	   	for(int i = 0; i < V; i++){
	   	    if(in[i] == 0){
	   	        q.push(i);
	   	    }
	   	}
	   	
	   	vector<int> res;
	   	while(!q.empty()){
	   	    
	   	    int curr = q.front();
	   	    res.push_back(curr);
	   	    q.pop();
	   	    
	   	    for(int i = 0; i < adj[curr].size(); i++){
	   	        in[adj[curr][i]]--;
	   	        if(in[adj[curr][i]] == 0){
	   	            q.push(adj[curr][i]);
	   	        }
	   	    }
	   	}
	   	
	   	if(res.size() == V){
	   	    return false;
	   	}
	   	return true;
	}
};
