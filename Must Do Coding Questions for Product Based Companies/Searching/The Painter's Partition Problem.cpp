class Solution
{
  public:
    long long paintersReq(long long mid, int arr[], int n){
        
        long long count = 1;
        
        long long sum = 0;
        
        for(int i = 0; i < n; i++){
            
            sum += arr[i];
            
            if(sum > mid){
                count++;
                sum = arr[i];
            }
        }
        return count;
    }
    long long minTime(int arr[], int n, int k)
    {
        if(k >= n){
            return *max_element(arr,arr+n);
        }
        
        long long lo = INT_MIN, hi = 0;
        
        for(int i = 0; i < n; i++){
            hi += arr[i];
            if(arr[i] > lo){
                lo = arr[i];
            }
        }
        
        long long minTime;
        
        while(lo <= hi){
            
            long long mid = (lo + hi)/2;
            
            if(paintersReq(mid,arr,n) <= k){
                minTime = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return minTime;
    }
};
