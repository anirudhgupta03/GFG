class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[2][y+1];
        
        bool bi;
        
        for(int i = 0; i <= x; i++){
            
            bi = i & 1;
            
            for(int j = 0; j <= y; j++){
                
                if(i == 0 || j == 0){
                    dp[bi][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[bi][j] = dp[1-bi][j-1] + 1;
                }
                else{
                    dp[bi][j] = max(dp[1-bi][j], dp[bi][j-1]);
                }
            }
        }
        
        return dp[bi][y];
    }
};
