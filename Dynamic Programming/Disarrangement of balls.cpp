//Ref: https://www.youtube.com/watch?v=XeAHpQ8AtvM
class Solution{
public:
    long int disarrange(int N){
        
        int mod = 1e9 + 7;
        if(N <= 2){
            return N - 1; 
        }
        long int dp[N+1];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i = 3; i <= N; i++){
            dp[i] = ((i - 1)*(dp[i-1] + dp[i-2])%mod)%mod;
        }
        
        return dp[N];
    }
};
