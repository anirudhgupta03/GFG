class Solution{
	public:
	vector<long long> findMissing(long long A[], long long B[],  
                 int N, int M) 
	{
	    vector<long long> res;
	    
	    unordered_map<long long, long long> umap;
	    
	    for(int i = 0; i < M; i++){
	        umap[B[i]]++;
	    }
	    
	    for(int i = 0; i < N; i++){
	        if(umap.find(A[i]) == umap.end()){
	            res.push_back(A[i]);
	        }
	    }
	    
	    return res;
	} 
};
