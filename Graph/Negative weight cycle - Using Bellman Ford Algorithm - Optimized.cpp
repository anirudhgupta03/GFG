class Solution{
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dist(n,INT_MAX);
	    
	    dist[0] = 0;
	    
	    int e = edges.size();
	    bool update;
	    int x;
	    for(int i = 0; i < n; i++)
	    {	       
	        x = -1;
	        for(int j = 0; j < e; j++)
	        {
	            if(dist[edges[j][0]] < INT_MAX && dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]]){
	                x = edges[j][1];
	                dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
	            }
	        }
	    }
	    
	    if(x == -1){
	        return 0;
	    }
	    return 1;
	}
};
