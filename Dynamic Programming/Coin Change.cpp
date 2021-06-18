//Recursive Approach
//Time Complexity - O(2^m)
//Space Complexity - O(1)
class Solution{
{
  public:
    long long int count( int S[], int m, int n )
    {
       if(n == 0){
           return 1;
       }
       if(m == 0){
           return 0;
       }
       
       if(S[m-1] <= n){
           return count(S,m,n-S[m-1]) + count(S,m-1,n);
       }
       else{
           return count(S,m-1,n);
       }
    }
};

//Top-Down Approach
//Time Complexity - O(m*n)
//Space Complexity - O(m*n)
{
  public:
    long long int solve(int m, int n, int S[], vector<vector<long long int>> &dp){
        
        if(n == 0){
            return dp[m][n] = 1;
        }
        if(m == 0){
            return dp[m][n] = 0;
        }
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        
        if(S[m-1] <= n){
            return dp[m][n] = solve(m,n-S[m-1],S,dp) + solve(m-1,n,S,dp);
        }
        else{
            return dp[m][n] = solve(m-1,n,S,dp);
        }
    }
    long long int count( int S[], int m, int n )
    {
       vector<vector<long long int>> dp(m+1,vector<long long int>(n+1,-1));
       
       return solve(m,n,S,dp);
    }
};
  
//Bottom-Up Approach
//Time Complexity - O(m*n)
//Space Complexity - O(m*n)
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       long long dp[m+1][n+1];
       
       for(int j = 1; j < n+1 ; j++){
           dp[0][j] = 0;
       }
       
       for(int i = 0; i < m + 1; i++){
           dp[i][0] = 1;
       }
       
       for(int i = 1; i < m + 1; i++){
           for(int j = 1; j < n + 1; j++){
               
               if(S[i-1] <= j){
                   dp[i][j] = dp[i][j-S[i-1]] + dp[i-1][j];
               }
               else{
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       
       return dp[m][n];
    }
};
