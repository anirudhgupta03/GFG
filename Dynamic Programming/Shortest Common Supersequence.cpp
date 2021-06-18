//Recursive Approach
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(string X, string Y, int m, int n){
        
        if(m == 0 || n == 0){
            return 0;
        }
        
        if(X[m-1] == Y[n-1]){
            return 1 + lcs(X,Y,m-1,n-1);
        }
        else{
            return max(lcs(X,Y,m-1,n), lcs(X,Y,m,n-1));
        }
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m + n - lcs(X,Y,m,n);   
    }
};

//Bottom-Up Approach
//Time Complexity - O(m*n)
//Space Complexity - O(m*n)
int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
    
    int dp[m+1][n+1];
    
    for(int i = 0; i < m + 1; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j < n + 1; j++){
        dp[0][j] = 0;
    }
    
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return m + n - dp[m][n];
}
