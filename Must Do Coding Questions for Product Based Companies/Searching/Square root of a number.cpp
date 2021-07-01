class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long lo = 1, hi = x;
        
        long long ans;
        
        while(lo <= hi){
            
            long long mid = (lo + hi)/2;
            
            if(mid*mid < x){
                ans = mid;
                lo = mid + 1;
            }
            else if(mid*mid == x){
                return mid;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
