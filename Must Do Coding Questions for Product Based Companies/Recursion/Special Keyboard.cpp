//Ref: https://www.youtube.com/watch?v=nyR8K63F2KY
class Solution{
public:
#define ll long long
    ll int solve(int n, int dp[]){
        
        if(n < 0) return -1;
        
        if(n <= 6) return n;
        
        int max_so_far = 0, max_As_with_i = 0, mult = 2;
        
        for(int i = n - 3; i >= 0; i--){
            
            if(dp[i] == -1){
                dp[i] = solve(i,dp);
            }
            
            max_As_with_i = mult*dp[i];
            
            if(max_As_with_i > max_so_far){
                max_so_far = max_As_with_i;
            }
            
            mult += 1;
        }
        return max_so_far;
    }
    long long int optimalKeys(int N){
        
        int dp[N];
        memset(dp,-1,sizeof(dp));
        
        return solve(N,dp);
    }
};
