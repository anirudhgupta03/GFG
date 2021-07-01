class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    
	    int lo = 0, hi = n - 1;
	    
	    while(lo <= hi){
	        
	        int mid = (lo + hi)/2;
	        
	        int prev = (mid+n-1)%n, next = (mid+1)%n;
	        
	        if(arr[mid] > arr[prev] && arr[mid] > arr[next]){
	            return arr[mid];
	        }
	        else if(arr[mid] > arr[prev]){
	            lo = mid + 1;
	        }
	        else{
	            hi = mid - 1;
	        }
	    }
	}
};
