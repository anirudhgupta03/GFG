class Solution{    
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int count = 1;
    	
    	int l = 0, r = 1;
    	
    	while(r < n){
    	    
    	    if(arr[r] > dep[l]){
    	        r++;
    	        l++;
    	    }
    	    else{
    	        count++;
    	        r++;
    	    }
    	}
    	
    	return count;
    }
};
