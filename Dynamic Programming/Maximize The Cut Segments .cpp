//Ref: youtube.com/watch?v=O0N4xn38Ncg
//Top-Down Approach
//Time Complexity - O(N)
//Space Complexity - O(N)
class Solution
{
    public:
    //Function to find the maximum number of cuts.
   int solve(int n, int x, int y, int z, int dp[]){
        
        if(n == 0){
            return dp[n] = 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        int a = INT_MIN,b = INT_MIN,c = INT_MIN;
        
        if(x <= n){
            a = solve(n-x,x,y,z,dp) + 1;
        }
        if(y <= n){
            b = solve(n-y,x,y,z,dp) + 1;
        }
        if(z <= n){
            c = solve(n-z,x,y,z,dp) + 1;
        }
        
        return dp[n] = max(a,max(b,c));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        int ans = solve(n,x,y,z,dp);
        
        if(ans < 0){
            return 0;
        }
        return ans;
    }
};

//Better
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int solve(int n, int x, int y, int z, int dp[]){
        
        if(n == 0){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int ans = INT_MIN;
        
        if(n >= x){
            int t1 = solve(n - x, x, y, z, dp);
            if(t1 != INT_MIN) ans = max(ans, t1 + 1);
        }
        if(n >= y){
            int t2 = solve(n - y, x, y, z, dp);
            if(t2 != INT_MIN) ans = max(ans, t2 + 1);
        }
        if(n >= z){
            int t3 = solve(n - z, x, y, z, dp);
            if(t3 != INT_MIN) ans = max(ans, t3 + 1);
        }
        
        return dp[n] = ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        int res = solve(n, x, y, z, dp);
        if(res == INT_MIN){
            return 0;
        }
        return res;
    }
};
