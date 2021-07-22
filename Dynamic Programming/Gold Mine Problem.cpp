class Solution{
public:
    int dx[3] = {0,-1,1};
    int dy[3] = {1,1,1};
    
    int solve(int x, int y, int &n, int &m, vector<vector<int>> &M, vector<vector<int>> &dp){
        
        if(y == m - 1){
            return M[x][y];
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int ans = INT_MIN;
        
        for(int i = 0; i < 3; i++){
            
            int xo = x + dx[i];
            int yo = y + dy[i];
            
            if(xo >= 0 && xo < n && yo < m){
                ans = max(ans, solve(xo, yo, n, m, M, dp) + M[x][y]);
            }
        }
        return dp[x][y] = ans;
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxAmount = INT_MIN;
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i = 0; i < n; i++){
            maxAmount = max(maxAmount, solve(i,0,n,m,M,dp));
        }
        
        return maxAmount;
    }
};
