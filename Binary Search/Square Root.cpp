//Ref: https://www.youtube.com/watch?v=Bsv3FPUX_BA&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=12
class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int lo = 1, hi = n;
        int ans;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(mid * mid <= n){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
};
