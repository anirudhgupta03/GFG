class Solution {
  public:
    #define ll long long
    int countSquares(int N) {
        
        ll lo = 1, hi = N, ans;
        
        while(lo <= hi){
            
            ll mid = (lo + hi)/2;
            
            if(mid*mid == N){
                ans = mid;
                break;
            }
            else if(mid*mid > N){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return ans - 1;
    }
};
