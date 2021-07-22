class Solution{
public:
    int nCr(int n, int r){
        
        if(n < r) return 0;
        if((n - r) < r) r = n - r;
        
        int mod = 1e9 + 7;
        
        int dp[r+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        
        for(int i = 1; i <= n ; i++){
            for(int j = min(i,r); j > 0; j--){
                dp[j] = (dp[j] + dp[j-1]) % mod;
            }
        }
        
        return dp[r];
    }
};
