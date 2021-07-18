//Ref: https://www.youtube.com/watch?v=GrV3MTR_Uk0
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int maxLen = 0, sum = 0;
	    
	    unordered_map<int,int> umap;
	    
	    for(int i = 0; i < n; i++){
	        
	        sum += arr[i];
	        
	        if(sum % k == 0){
	            maxLen = i + 1;
	        }
	        
	        
	        int rem = sum % k;
	        if(rem < 0){
	            rem += k; 
	        }
	        
	        if(umap.find(rem) != umap.end()){
	            maxLen = max(maxLen,i - umap[rem]);
	        }
	        else{
	            umap[rem] = i;
	        }
	    }
	    return maxLen;
	}
};
