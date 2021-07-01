class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int pages, int arr[], int n, int m){
        
        int count = 1, sum = 0;
        
        for(int i = 0; i < n; i++){
            
            sum += arr[i];
            
            if(sum > pages){
                count++;
                sum = arr[i];
            }
        }
        
        if(count <= m){
            return true;
        }
        return false;
    }
    int findPages(int arr[], int n, int m) 
    {
        if(m > n){
            return -1;
        }
        
        int lo = INT_MIN, hi = 0;
        
        for(int i = 0; i < n; i++){
            lo = max(lo,arr[i]);
            hi += arr[i];
        }
        
        int ans;
        
        while(lo <= hi){
            
            int mid = (lo + hi)/2;
            
            if(isPossible(mid,arr,n,m)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
