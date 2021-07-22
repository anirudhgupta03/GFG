class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        cpp_int dp[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = 0;
        }
        
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            
            int l = 0, r = i - 1;
            
            while(l <= i - 1){
                dp[i] += dp[l]*dp[r];
                l++;
                r--;
            }
        }
        
        return dp[n];
    }
};
