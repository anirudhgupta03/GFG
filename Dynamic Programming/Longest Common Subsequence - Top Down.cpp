int LCS(int x,int y , string s1, string s2, vector<vector<int>> &dp){
    if(x == 0 || y == 0){
        return 0;
    }
    
    if(dp[x][y] != -1){
        return dp[x][y];
        
    }
    if(s1[x-1] == s2[y-1]){
        return dp[x][y] = 1 + LCS(x - 1, y - 1, s1, s2,dp);
    }
    else{
        return dp[x][y] = max(LCS(x - 1, y, s1, s2,dp), LCS(x, y - 1, s1, s2, dp));
    }
}
int lcs(int x, int y, string s1, string s2){
    
    vector<vector<int>> dp(x+1,vector<int>(y+1));
   
    for(int i = 0; i < x + 1; i++){
        for(int j = 0; j < y + 1; j++){
            dp[i][j] = -1;
        }
    }
    
    return LCS(x,y,s1,s2,dp);
}
