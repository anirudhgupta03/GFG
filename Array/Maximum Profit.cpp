class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        
        int dp[K+1][N];
        
        for(int i = 0; i < K + 1; i++){
            
            int temp = INT_MIN;
            
            for(int j = 0; j < N; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i][j-1];
                    
                    temp = max(temp,dp[i-1][j-1] - A[j-1]);
                    
                    dp[i][j] = max(dp[i][j], temp + A[j]);
                }
            }
        }
        
        return dp[K][N-1];
    }
};
