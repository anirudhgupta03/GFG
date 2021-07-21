class Solution{
public:

	// Function to find maximum product subarray
	
	#define ll long long
	long long maxProduct(int *arr, int n) {
	    
	    ll currMaxProd = arr[0], currMinProd = arr[0], prevMinProd = arr[0], prevMaxProd = arr[0];
	    
	    ll ans = arr[0];
	    
	    for(int i = 1; i < n; i++){
	        
	        ll p1 = prevMaxProd*arr[i], p2 = prevMinProd*arr[i], p3 = arr[i];
	        
	        currMaxProd = max(p1, max(p2,p3));
	        currMinProd = min(p1, min(p2,p3));
	        
	        ans = max(ans,currMaxProd);
	        
	        prevMaxProd = currMaxProd;
	        prevMinProd = currMinProd;
	    }
	    
	    return ans;
	}
};
