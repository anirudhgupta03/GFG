class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> res;
	    
	    vector<int> in(V,0);
	    
	    for(int i = 0; i < V; i++){
	        vector<int> temp = adj[i];
	        for(int j = 0; j < temp.size(); j++){
	            in[temp[j]]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(in[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        
	        int curr = q.front();
	        q.pop();
	        res.push_back(curr);
	        for(int i = 0; i < adj[curr].size(); i++){
	            int child = adj[curr][i];
	            in[child]--;
	            
	            if(in[child] == 0){
	                q.push(child);
	            }
	        }
	    }
	    
	    return res;
	}
};
