	class Solution{
	public:
	#define ll long long
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    ll count = 0;
	    
	    sort(arr,arr+n);
	    
	    for(int i = n - 1; i >= 2; i--){
	        
	        int lo = 0, hi = i - 1;
	        
	        while(lo < hi){
	            
	            ll s = arr[i] + arr[lo] + arr[hi];
	            
	            if(s >= sum){
	                hi--;
	            }
	            else{
	                count += hi - lo;
	                lo++;
	            }
	        }
	    }
	    
	    return count;
	}
		 

};
