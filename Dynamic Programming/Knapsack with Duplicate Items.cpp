//Recursive Approach
//Time Complexity - O(2^N)
//Space Complexity - O(1)
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        if(W == 0 || N == 0){
            return 0;
        }
        
        if(wt[N-1] <= W){
            return max(val[N-1] + knapSack(N,W-wt[N-1],val,wt), knapSack(N-1,W,val,wt));
        }
        else{
            return knapSack(N-1,W,val,wt);
        }
    }
};

//Top-Down Approach
//Time Complexity - O(N*W)
//Space Complexity - O(N*W)
class Solution{
public:
    int solve(int N, int W, int val[], int wt[], vector<vector<int>> &dp){
        
        if(N == 0 || W == 0){
            return dp[N][W] = 0;
        }
        
        if(dp[N][W] != -1){
            return dp[N][W];
        }
        
        if(wt[N-1] <= W){
            return dp[N][W] = max(val[N-1] + solve(N,W - wt[N-1],val,wt,dp), solve(N-1,W,val,wt,dp));
        }
        else{
            return dp[N][W] = solve(N-1,W,val,wt,dp);
        }
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        
        return solve(N,W,val,wt,dp);
    }
};

//Bottom-Up Approach
//Time Complexity - O(N*W)
//Space Complexity - O(N*W)
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1];
        
        for(int i = 0; i < N + 1; i++){
            for(int j = 0; j < W + 1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < N + 1; i++){
            for(int j = 1; j < W + 1; j++){
                
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][W];
    }
};
