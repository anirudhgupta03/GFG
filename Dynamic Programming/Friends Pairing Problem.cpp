class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int dp[n+1], mod = 1e9 + 7;
        
        if(n <= 2){
            return n;
        }
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(long long i = 3; i <= n; i++){
            dp[i] = ((dp[i-1]%mod) + (((i-1)%mod)*(dp[i-2])%mod))%mod;
        }
        
        return dp[n] % mod;
    }
};  
