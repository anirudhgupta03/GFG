class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        int dp[N];
        for(int i = 0; i < N; i++){
            dp[i] = 1;
        }
        
        int maxLen = 1;
        for(int i = 1; i < N; i++){
            
            for(int j = 0; j < i; j++){
                
                if(abs(A[i]-A[j]) == 1){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            maxLen = max(maxLen,dp[i]);
        }
        
        return maxLen;
    }
};
