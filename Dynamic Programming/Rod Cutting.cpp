
//Recursive Approach
//Time Complexity - O(2^N)
//Space Complexity - O(1)
class Solution{
  public:
    int solve(int n1, int n2, int price[], int len[]){
        
        if(n1 == 0 || n2 == 0){
            return 0;
        }
        
        if(len[n1-1] <= n2){
            return max(price[n1-1] + solve(n1,n2-len[n1-1],price,len) , solve(n1-1,n2,price,len));
        }
        else{
            return solve(n1-1,n2,price,len);
        }
    }
    int cutRod(int price[], int n) {
        
        int len[n];
        for(int i = 0; i < n; i++){
            len[i] = i + 1;
        }
        
        return solve(n,n,price,len);
    }
};

//Top-Down Approach
//Time Complexity - O(N*N)
//Space Complexity - O(N^2)
class Solution{
  public:
    int solve(int n1, int n2, int price[], int len[], vector<vector<int>> &dp){
        
        if(n1 == 0 || n2 == 0){
            return dp[n1][n2] = 0;
        }
        
        if(dp[n1][n2] != -1){
            return dp[n1][n2];
        }
        
        if(len[n1-1] <= n2){
            return dp[n1][n2] = max(price[n1-1] + solve(n1,n2-len[n1-1],price,len,dp), solve(n1-1,n2,price,len,dp));
        }
        else{
            return dp[n1][n2] = solve(n1-1,n2,price,len,dp);
        }
    }
    int cutRod(int price[], int n) {
        
        int len[n];
        
        for(int i = 0; i < n; i++){
            len[i] = i + 1;
        }
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(n,n,price,len,dp);
    }
};

//Bottom-Up Approach
//Time Complexity - O(N*N)
//Space Complexity - O(N^2)
class Solution{
  public:
    int cutRod(int price[], int n) {
        
        int len[n];
        
        for(int i = 0; i < n; i++){
            len[i] = i + 1;
        }
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        for(int i = 0; i < n + 1; i++){
            for(int j = 0; j < n + 1; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(len[i-1] <= j){
                    dp[i][j] = max(dp[i][j-len[i-1]] + price[i-1], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][n];
    }
};
