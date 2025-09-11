//Ref: https://www.youtube.com/watch?v=rjEJeYCasHs&list=PLF6ChxadzFf8vjafLIxxbKUfarW4V4IOh&index=11
#define ll long long
class Solution {
  public:
    int nthPower(ll mid, int n, int m){
        ll val = 1;
        for(int i = 1; i <= n; i++){
            val *= mid;
            if(val > m){
                return 2;
            }
        }
        if(val == m) return 1;
        return 0;
    }
    int nthRoot(int n, int m) {
        ll lo = 1, hi = m;
        while(lo <= hi){
            ll mid = lo + (hi - lo)/2;
            ll nthPowerValue = nthPower(mid, n, m);
            if(nthPowerValue == 1){
                return mid;
            }
            else if(nthPowerValue == 0){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return -1;
    }
};
