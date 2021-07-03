class Solution{   
public:
    int solve(int lo, int hi, int A[], vector<vector<int>> &dp){
        
        if(lo > hi){
            return 0;
        }
         
         if(dp[lo][hi] != -1){
            return dp[lo][hi];
        }
            
        int a = 0,b = 0,c = 0,d = 0;
            
        a = solve(lo + 2, hi, A, dp) + A[lo];
        
        b = solve(lo + 1, hi - 1, A, dp) + A[lo];
            
        c = solve(lo, hi - 2, A, dp) + A[hi];
        
        d = solve(lo + 1, hi - 1, A, dp) + A[hi];
            
        return dp[lo][hi] = max(min(a,b),min(c,d));
    }
    bool is1winner(int N,int arr[]) {
        
        int totalSum = 0;
        
        for(int i = 0; i < N; i++){
            totalSum += arr[i];
        }
        
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        
        int x = solve(0,N-1,arr,dp);
        
        if(totalSum - x < x){
            return 1;
        }  
        return 0;
    }
};
