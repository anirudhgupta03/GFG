//Ref: https://www.youtube.com/watch?v=-ToUWP1Yxzo
//Top-Down Approach
//Time Complexity - O(M*N)
//Space Complexity - O(M*N) + O(M+N)
class Solution {
  public:
    int result;
    int solve(int ind1, int ind2, string& s1, string& s2, vector<vector<int>>& dp){
        if(ind1 == 0 || ind2 == 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(s1[ind1 - 1] == s2[ind2 - 1]){
            int p1 = solve(ind1 - 1, ind2 - 1, s1, s2, dp);
            int p2 = solve(ind1 - 1, ind2, s1, s2, dp);
            int p3 = solve(ind1, ind2 - 1, s1, s2, dp);
            result = max({result, p1 + 1, p2, p3});
            return dp[ind1][ind2] = p1 + 1;
        }
        else{
            int p1 = solve(ind1 - 1, ind2, s1, s2, dp);
            int p2 = solve(ind1, ind2 - 1, s1, s2, dp);
            result = max({result, p1, p2});
            return dp[ind1][ind2] = 0;
        }
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        result = 0;
        int l1 = s1.length(), l2 = s2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
        solve(l1, l2, s1, s2, dp);
        return result;
    }
};

//Bottom-Up Approach
//Time Complexity - O(M*N)
//Space Complexity - O(M*N)
class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        int result = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    result = max(result,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return result;
    }
};
