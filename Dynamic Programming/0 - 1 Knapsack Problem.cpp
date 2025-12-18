//Recursive Approach
// Time Complexity - O(2^n). 
// As there are redundant subproblems.
// Auxiliary Space - O(1). 
// As no extra data structure has been used for storing values.
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int ind, int n, int wt[], int val[], int W){
        
        if(W == 0 || ind == n){  //Base Conditions 1)Knapsack is empty 2)No items
            return 0; 
        }
        
        if(wt[ind] <= W){
            return max(solve(ind+1,n,wt,val,W-wt[ind]) + val[ind], solve(ind+1,n,wt,val,W));
        }
        else{
            return solve(ind+1,n,wt,val,W);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return solve(0,n,wt,val,W);
    }
};

//Top-Down Approach
//Time Complexity - O(n*W)
//Space Complexity - O(n*W)
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

//Bottom-Up Approach
//Tabulation
//Time Complexity - O(n*W)
//Space Complexity - O(n*W)
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1];
       
       for(int i = 0; i <= n; i++){
           for(int j = 0; j <= W; j++){
               
               if(i == 0 || j == 0){
                   dp[i][j] = 0;
               }
               else if(wt[i-1] <= j){
                   dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1], dp[i-1][j]);
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }
};


//Bottom-Up Approach
//Tabulation + Space Optimization
//Time Complexity - O(n*W)
//Space Complexity - O(W)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<int> dp(W + 1, 0);
        
        for(int i = 0; i <= n; i++){
            vector<int> currdp(W + 1, 0);
            for(int j = 0; j <= W; j++){
                if(i == 0 || j == 0){
                    currdp[j] = 0;
                }
                else{
                    currdp[j] = dp[j];
                    if(wt[i - 1] <= j){
                        currdp[j] = max(currdp[j], dp[j - wt[i - 1]] + val[i - 1]);
                    }
                }
            }
            dp = currdp;
        }
        return dp[W];
    }
};
