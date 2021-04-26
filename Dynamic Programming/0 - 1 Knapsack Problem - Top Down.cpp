class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int n, int W, int wt[], int val[], vector<vector<int>> &dp){
        
        if(n == 0 || W == 0){
            return 0;
        }
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        if(wt[n-1] <= W){
            dp[n][W] = max(val[n-1] + solve(n-1,W-wt[n-1],wt,val,dp), solve(n-1,W,wt,val,dp));
        }
        else{
            dp[n][W] = solve(n-1,W,wt,val,dp);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
      
       solve(n,W,wt,val,dp);
       
       return dp[n][W];
    }
};
