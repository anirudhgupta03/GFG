//Method - 1
class Solution{
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dist(n,INT_MAX);
	    
	    dist[0] = 0;
	    
	    int e = edges.size();
	    bool update;
	    for(int i = 0; i < n - 1; i++)
	    {
	        update = false;
	        for(int j = 0; j < e; j++)
	        {
	            if(dist[edges[j][0]] < INT_MAX && dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]]){
	                update = true;
	                dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
	            }
	        }
	        if(!update){
	            break;
	        }
	    }
	    
	    for(int j=0; j<e and update==true; ++j)
		{
			if(dist[edges[j][0]] < INT_MAX && dist[edges[j][0]] + edges[j][2] < dist[edges[j][1]]){
	                return true;
	       }
		}
		return false;
	}
};

//Method - 2
class Solution{
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dist(n,INT_MAX);
	    
	    dist[0] = 0;
	    
	    bool flag = false;
	    
	    for(int i = 0; i < n; i++){
	        
	        flag = false;
	        
	        for(int j = 0; j < edges.size(); j++){
	            
	            int a = edges[j][0], b = edges[j][1], w = edges[j][2];
	            
	            if(dist[a] != INT_MAX && dist[a] + w < dist[b]){
	                dist[b] = dist[a] + w;
	                flag = true;
	            }
	        }
	    }
	    
	    return flag;
	}
};
