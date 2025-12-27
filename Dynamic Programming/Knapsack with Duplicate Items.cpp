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
class Solution {
  public:
    int solve(int ind, vector<int>& val, vector<int>& wt, int capacity, vector<vector<int>>& dp){
        if(ind == -1 || capacity == 0){
            return 0;    
        }
        if(dp[ind][capacity] != -1){
            return dp[ind][capacity];
        }
        int take = INT_MIN;
        if(wt[ind] <= capacity){
            take = solve(ind, val, wt, capacity - wt[ind], dp) + val[ind];
        }
        int notTake = solve(ind - 1, val, wt, capacity, dp);
        return dp[ind][capacity] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(n - 1, val, wt, capacity, dp);
    }
};

//Bottom-Up Approach
//Time Complexity - O(N*W)
//Space Complexity - O(N*W)
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= capacity; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    int take = INT_MIN;
                    if(wt[i - 1] <= j){
                        take = dp[i][j - wt[i - 1]] + val[i - 1];
                    }
                    int notTake = dp[i - 1][j];
                    dp[i][j] = max(take, notTake);
                }
            }
        }
        return dp[n][capacity];
    }
};

//Tabulation + Space Optimization
//Time Complexity - O(N*W)
//Space Complexity - O(W)
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<int> prevDP(capacity + 1, 0);
        for(int i = 0; i <= n; i++){
            vector<int> currDP(capacity + 1, 0);
            for(int j = 0; j <= capacity; j++){
                if(i == 0 || j == 0){
                    currDP[j] = 0;
                }
                else{
                    int take = INT_MIN;
                    if(wt[i - 1] <= j){
                        take = currDP[j - wt[i - 1]] + val[i - 1];
                    }
                    int notTake = prevDP[j];
                    currDP[j] = max(take, notTake);
                }
            }
            prevDP = currDP;
        }
        return prevDP[capacity];
    }
};
