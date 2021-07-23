//Ref: https://www.youtube.com/watch?v=pyO2FJE7G9o
class Solution {
  public:
    long long int countBT(int h) { 
        
        int mod = 1e9 + 7;
        
        long long dp[h+1];
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= h; i++){
            dp[i] = (dp[i-1]*(2*dp[i-2]%mod + dp[i-1]%mod)%mod)%mod;
        }
        
        return dp[h];
    }
};
