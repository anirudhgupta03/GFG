class Solution{
    
int selectMinVertex(vector<int> &wt, vector<int> &vis){
    int minimum = INT_MAX;
    int vertex;

    for(int i = 0; i < wt.size(); i++){

        if(vis[i] == 0 && wt[i] < minimum){
            vertex = i;
            minimum = wt[i];
        }
    }
    return vertex;
}
	public:
	// Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    void prims(vector<int> &wt, vector<int> &vis, vector<vector<int>> adj[], int V){
        
        int src = 0;
        
        for(int i = 0; i <= V -2; i++){
            
            int src = selectMinVertex(wt, vis);
            vis[src] = 1;
            
            for(int j = 0; j < adj[src].size(); j++){
                
                if(vis[adj[src][j][0]] == 0 && adj[src][j][1] < wt[adj[src][j][0]]){
                    
                    wt[adj[src][j][0]] = adj[src][j][1];
                }
            }
            
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        vector<int> wt(V,INT_MAX);
        vector<int> vis(V,0);
        
        wt[0] = 0;
        
        int ans = 0;
        
        prims(wt, vis, adj, V);
        
        for(int i = 0; i < V; i++){
            ans += wt[i];
        }
        return ans;
    }
};

//Kruskal
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	bool static cmp(vector<int> v1, vector<int> v2){
	    return v1[2] < v2[2];
	}
	int findP(int node, vector<int> &par){
	    
	    if(par[node] == -1){
	        return node;
	    }
	    return par[node] = findP(par[node],par);
	}
	void unionP(int node1, int node2, vector<int> &par){
	    par[node2] = node1;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> al;
        
        for(int i = 0; i < V; i++){
            for(int j = 0; j < adj[i].size(); j++){
                al.push_back({i,adj[i][j][0],adj[i][j][1]});
            }
        }
        
        int minWt = 0;
        
        vector<int> par(V,-1);
        
        sort(al.begin(),al.end(),cmp);
        
        for(int i = 0; i < al.size(); i++){
            
            int a = al[i][0], b = al[i][1], w = al[i][2];
            
            int para = findP(a,par);
            int parb = findP(b,par);
            
            if(para != parb){
                minWt += w;
                unionP(para,parb,par);
            }
        }
        
        return minWt;
    }
};
