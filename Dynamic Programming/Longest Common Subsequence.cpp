//Recursive Approach
//Time Complexity - O(2^min(x,y))
//Space Complexity - O(1)
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        if(x == 0 || y == 0){
            return 0;
        }
        
        if(s1[x-1] == s2[y-1]){
            return 1 + lcs(x-1,y-1,s1,s2);
        }
        else{
            return max(lcs(x-1,y,s1,s2), lcs(x,y-1,s1,s2));
        }
    }
};

//Top-Down Approach
//Time Complexity - O(x*y)
//Space Complexity - O(x*y)
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(int x, int y, string &s1, string &s2, vector<vector<int>> &dp){
        
        if(x == 0 || y == 0){
            return dp[x][y] = 0;
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        if(s1[x-1] == s2[y-1]){
            return dp[x][y] = 1 + solve(x-1,y-1,s1,s2,dp);
        }
        else{
            return dp[x][y] = max(solve(x-1,y,s1,s2,dp), solve(x,y-1,s1,s2,dp));
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        
        return solve(x,y,s1,s2,dp);
    }
};


//Bottom-Up Approach
//Time Complexity - O(x*y)
//Space Complexity - O(x*y)
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
        
        for(int i = 0; i <= x; i++){
            for(int j = 0; j <= y; j++){
                
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[x][y];
    }
};
