class Solution{
    
	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        int wt[N];
        
        for(int i = 0; i < N; i++){
            wt[i] = i + 1;
        }
        
        int dp[N+1][W+1];
        
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= W; j++){
                
                if(j == 0){
                    dp[i][j] = 0;
                }
                else if(i == 0){
                    dp[i][j] = INT_MAX;
                }
                else if(wt[i-1] <= j && cost[i-1] != -1 && dp[i][j-wt[i-1]] != INT_MAX){
                    dp[i][j] = min(dp[i][j-wt[i-1]] + cost[i-1],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        if(dp[N][W] == INT_MAX){
            return -1;
        }
        return dp[N][W];
	} 
};
